#include "qt_installer_framework.h"
#include <cstdlib>
#include<iostream>
#include <fstream>
#include <algorithm>
#include <filesystem>
//#include <execution>


#include <unistd.h>
#include <CLI/CLI.hpp>

size_t findMagicCookie(std::ifstream &stream, uint64_t magicCookie) {
	stream.seekg(0, std::ios_base::end);
	const uint64_t fileSize = stream.tellg();

	const size_t markerSize = sizeof(decltype(magicCookie));
	const uint64_t maxSearch = std::min((1024UL * 1024UL), fileSize);

	std::vector<uint64_t> data;
	data.reserve(maxSearch/markerSize);
	data.resize(maxSearch/markerSize);

	stream.seekg(fileSize - maxSearch, std::ios_base::beg);
	stream.read(reinterpret_cast<char*>(data.data()), maxSearch);

	auto found = std::find(begin(data), end(data), magicCookie);
	//auto found = std::find(begin(data), end(data), magicCookie, std::execution::par_unseq);
	if(found == end(data)){
		return 0;
	}

	return fileSize - maxSearch + (found-begin(data)) * markerSize;
}

class Mode{
public:
	std::filesystem::path fileNameP;
	std::filesystem::path outputDirP;
	Mode(std::string &fileName, std::string &outputDir): fileNameP(std::filesystem::canonical(fileName)), outputDirP(std::filesystem::canonical(outputDir)){
		
	}
	~Mode() = default;

	virtual void enterCollection(std::string collectionName) = 0;
	virtual void processArchive(uint64_t start, uint64_t size, std::string name) = 0;
	virtual void emptyCollection(std::string collectionName);

	void operator()();
};

void Mode::operator()(){
	std::ifstream is(fileNameP, std::ios::in | std::ios::binary);

	size_t magic_cookie_offset = findMagicCookie(is, 0xc2630a1c99d668f8LL);
	if(magic_cookie_offset){
		std::cerr << "p_magic_cookie_offset " << magic_cookie_offset << std::endl;
	}else{
		std::cerr << "This is not a QIF archive!" << std::endl;
		return;
	}

	is.seekg(0, std::ios_base::beg);
	kaitai::kstream s(&is);
	qt_installer_framework_t parsed(magic_cookie_offset, &s);
	std::cerr << "parsed initial " << std::endl;
	std::cerr << "end_of_binary_content " << parsed.end_of_binary_content() << std::endl;
	auto *header = parsed.header();
	auto *binary_descriptor = header->binary_descriptor();


	for(auto &&coll: *(binary_descriptor->segments_descriptor()->collections()->collections())) {
		//seg=colls[coll.name.value] = help_carvPrefixstr=""OrderedDict()
		auto &ress=*(coll->segment()->resources());
		if(ress.size()){
			enterCollection(coll->name()->value());
			
			for(auto &&resource: ress) {
				processArchive(resource->segment()->start(), resource->segment()->size(), resource->name()->value());
			}
		}
		else{
			emptyCollection(coll->name()->value());
		}
	}
}

void Mode::emptyCollection(std::string collectionName){
	std::cout << "# Skipping " << collectionName << " : no files" << std::endl;
}

struct CarvFSMode: public Mode{
public:
	std::filesystem::path carvFsMountDirP;
	std::filesystem::path carvFsChunksDir;
	bool createBashScript;
	std::filesystem::path subDirName;

	CarvFSMode(std::string &fileName, std::string &carvFsMountDir, std::string &outputDir, bool createBashScript);
	~CarvFSMode() = default;

	virtual void enterCollection(std::string subPackageName);
	virtual void processArchive(uint64_t start, uint64_t size, std::string name);
};

CarvFSMode::CarvFSMode(std::string &fileName, std::string &carvFsMountDir, std::string &outputDir, bool createBashScript): carvFsMountDirP(std::filesystem::canonical(carvFsMountDir)), Mode(fileName, outputDir), createBashScript(createBashScript){
	std::cout << carvFsMountDir << std::endl;
	std::cout.flush();
	carvFsChunksDir = carvFsMountDirP / "0" / "CarvFS";
}

void CarvFSMode::enterCollection(std::string subPackageName){
	subDirName = outputDirP / subPackageName;
	if(createBashScript){
		std::cout << "mkdir " << subDirName << std::endl;
	}else{
		std::filesystem::create_directory(subDirName);
	}
}


void CarvFSMode::processArchive(uint64_t start, uint64_t size, std::string name){
	std::filesystem::path carvFsFileName;
	{
		std::stringstream carvFsFileShortNameBuf;
		carvFsFileShortNameBuf << start << "+" << size << ".crv";
		carvFsFileName = carvFsChunksDir / carvFsFileShortNameBuf.str();
	}

	std::filesystem::path resFileName = subDirName / name;

	if(createBashScript){
		std::cout << "ln -s " << carvFsFileName  << " " << resFileName << std::endl;
	}else{
		std::filesystem::create_symlink(carvFsFileName, resFileName);
	}
}


struct DDMode: public Mode{
public:
	std::filesystem::path subDirName;

	DDMode(std::string &fileName, std::string &outputDir);
	~DDMode() = default;

	virtual void enterCollection(std::string subPackageName);
	virtual void processArchive(uint64_t start, uint64_t size, std::string name);
};

DDMode::DDMode(std::string &fileName, std::string &outputDir): Mode(fileName, outputDir){}

void DDMode::enterCollection(std::string subPackageName){
	subDirName = outputDirP / subPackageName;
	std::cout << "mkdir " << subDirName << std::endl;
}


void DDMode::processArchive(uint64_t start, uint64_t size, std::string name){
	std::stringstream ddCommandBuf;
	std::filesystem::path resFileName = subDirName / name;

	std::cout << "dd if=" << fileNameP  << " of=" << resFileName << " bs=1 count=" << size << " skip=" << start << std::endl;
}


int main(int argc, char **argv) {
	CLI::App app{"QtInstallerFramework Extractor"};
	app.require_subcommand(1);

	std::string fileName{"./qt-opensource-windows-x86-5.13.0.exe"};
	std::string carvFsMountDir{"./carvFS"};
	std::string outputDir{"./out"};
	bool createBashScript=true;

	auto carvFsSc = app.add_subcommand("carvfs", "Output a bash script creating symlinks into CarvFs (https://github.com/DNPA/carvfs)");
	carvFsSc->callback([&](){
		CarvFSMode modeCarvFs(fileName, carvFsMountDir, outputDir, createBashScript);
		modeCarvFs();
	});

	app.add_option("inputFile,-f,--file", fileName, "A Qt installer framework installer executable")->required()->check(CLI::ExistingFile);
	app.add_option("outDir,-O,--outDir", outputDir, "A dir where archives should be placed");

	carvFsSc->add_option("carvFsMountDir,-M,--carvFsMountDir", carvFsMountDir, "A dir where CarvFS will be mounted");
	carvFsSc->add_flag("--bash", createBashScript, "Create a bash script for manual examination");

	auto ddSc = app.add_subcommand("dd", "Output a bash script copying the parts using dd)");
	ddSc->callback([&](){
		DDMode modeCarvFs(fileName, outputDir);
		modeCarvFs();
	});

	#ifdef _WIN32
		app.allow_windows_style_options();
	#endif

	std::cout << carvFsMountDir << " 1" << std::endl;
	std::cout.flush();
	try {
		app.parse(argc, argv);
	} catch (const CLI::ParseError &e) {
		return app.exit(e);
	}

	return 0;
}
