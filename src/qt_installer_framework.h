#ifndef QT_INSTALLER_FRAMEWORK_H_
#define QT_INSTALLER_FRAMEWORK_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

/**
 * Qt installer framework is a set of libs to make SFX installers. Instalers usually contain 7zip-compressed archives.
 * \sa https://github.com/qtproject/installer-framework/blob/master/src/libs/installer/binarycontent.cpp#L111 Source
 * \sa https://github.com/qtproject/installer-framework/blob/master/src/libs/installer/binarycontent.h#L45 Source
 */

class qt_installer_framework_t : public kaitai::kstruct {

public:
	class array_t;
	class string_t;
	class header_t;

	qt_installer_framework_t(uint64_t p_magic_cookie_offset, kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, qt_installer_framework_t* p__root = 0);

private:
	void _read();

public:
	~qt_installer_framework_t();

	class array_t : public kaitai::kstruct {

	public:

		array_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, qt_installer_framework_t* p__root = 0);

	private:
		void _read();

	public:
		~array_t();

	private:
		uint64_t m_size;
		std::string m_value;
		qt_installer_framework_t* m__root;
		kaitai::kstruct* m__parent;

	public:
		uint64_t size() const { return m_size; }
		std::string value() const { return m_value; }
		qt_installer_framework_t* _root() const { return m__root; }
		kaitai::kstruct* _parent() const { return m__parent; }
	};

	class string_t : public kaitai::kstruct {

	public:

		string_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, qt_installer_framework_t* p__root = 0);

	private:
		void _read();

	public:
		~string_t();

	private:
		uint64_t m_size;
		std::string m_value;
		qt_installer_framework_t* m__root;
		kaitai::kstruct* m__parent;

	public:
		uint64_t size() const { return m_size; }
		std::string value() const { return m_value; }
		qt_installer_framework_t* _root() const { return m__root; }
		kaitai::kstruct* _parent() const { return m__parent; }
	};

	class header_t : public kaitai::kstruct {

	public:
		class marker_identifier_t;
		class cookie_identifier_t;
		class range_t;
		class binary_descriptor_t;

		header_t(kaitai::kstream* p__io, qt_installer_framework_t* p__parent = 0, qt_installer_framework_t* p__root = 0);

	private:
		void _read();

	public:
		~header_t();

		class marker_identifier_t : public kaitai::kstruct {

		public:

			enum type_t {
				TYPE_INSTALLER = 51,
				TYPE_UNINSTALLER = 52,
				TYPE_UPDATER = 53,
				TYPE_PACKAGE_MANAGER = 54
			};

			marker_identifier_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t::binary_descriptor_t* p__parent = 0, qt_installer_framework_t* p__root = 0);

		private:
			void _read();

		public:
			~marker_identifier_t();

		private:
			type_t m_type;
			std::string m_signature;
			qt_installer_framework_t* m__root;
			qt_installer_framework_t::header_t::binary_descriptor_t* m__parent;

		public:
			type_t type() const { return m_type; }
			std::string signature() const { return m_signature; }
			qt_installer_framework_t* _root() const { return m__root; }
			qt_installer_framework_t::header_t::binary_descriptor_t* _parent() const { return m__parent; }
		};

		class cookie_identifier_t : public kaitai::kstruct {

		public:

			enum type_t {
				TYPE_BINARY = 248,
				TYPE_DATA = 249
			};

			cookie_identifier_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t* p__parent = 0, qt_installer_framework_t* p__root = 0);

		private:
			void _read();

		public:
			~cookie_identifier_t();

		private:
			type_t m_type;
			std::string m_signature;
			qt_installer_framework_t* m__root;
			qt_installer_framework_t::header_t* m__parent;

		public:
			type_t type() const { return m_type; }
			std::string signature() const { return m_signature; }
			qt_installer_framework_t* _root() const { return m__root; }
			qt_installer_framework_t::header_t* _parent() const { return m__parent; }
		};

		class range_t : public kaitai::kstruct {

		public:

			range_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, qt_installer_framework_t* p__root = 0);

		private:
			void _read();

		public:
			~range_t();

		private:
			bool f_start;
			int64_t m_start;

		public:
			int64_t start();

		private:
			int64_t m_start_read;
			int64_t m_size;
			qt_installer_framework_t* m__root;
			kaitai::kstruct* m__parent;

		public:
			int64_t start_read() const { return m_start_read; }
			int64_t size() const { return m_size; }
			qt_installer_framework_t* _root() const { return m__root; }
			kaitai::kstruct* _parent() const { return m__parent; }
		};

		class binary_descriptor_t : public kaitai::kstruct {

		public:
			class segments_descriptor_t;

			binary_descriptor_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t* p__parent = 0, qt_installer_framework_t* p__root = 0);

		private:
			void _read();

		public:
			~binary_descriptor_t();

			class segments_descriptor_t : public kaitai::kstruct {

			public:
				class operations_t;
				class collections_t;

				segments_descriptor_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t::binary_descriptor_t* p__parent = 0, qt_installer_framework_t* p__root = 0);

			private:
				void _read();

			public:
				~segments_descriptor_t();

				class operations_t : public kaitai::kstruct {

				public:
					class operation_t;

					operations_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t* p__parent = 0, qt_installer_framework_t* p__root = 0);

				private:
					void _read();

				public:
					~operations_t();

					class operation_t : public kaitai::kstruct {

					public:

						operation_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::operations_t* p__parent = 0, qt_installer_framework_t* p__root = 0);

					private:
						void _read();

					public:
						~operation_t();

					private:
						string_t* m_name;
						string_t* m_xml;
						qt_installer_framework_t* m__root;
						qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::operations_t* m__parent;

					public:
						string_t* name() const { return m_name; }
						string_t* xml() const { return m_xml; }
						qt_installer_framework_t* _root() const { return m__root; }
						qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::operations_t* _parent() const { return m__parent; }
					};

				private:
					uint64_t m_count;
					std::vector<operation_t*>* m_operations;
					uint64_t m_reserved;
					qt_installer_framework_t* m__root;
					qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t* m__parent;

				public:
					uint64_t count() const { return m_count; }
					std::vector<operation_t*>* operations() const { return m_operations; }

					/**
					 * read it, but deliberately not used
					 */
					uint64_t reserved() const { return m_reserved; }
					qt_installer_framework_t* _root() const { return m__root; }
					qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t* _parent() const { return m__parent; }
				};

				class collections_t : public kaitai::kstruct {

				public:
					class collection_t;

					collections_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t* p__parent = 0, qt_installer_framework_t* p__root = 0);

				private:
					void _read();

				public:
					~collections_t();

					class collection_t : public kaitai::kstruct {

					public:
						class segment_t;

						collection_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t* p__parent = 0, qt_installer_framework_t* p__root = 0);

					private:
						void _read();

					public:
						~collection_t();

						class segment_t : public kaitai::kstruct {

						public:
							class resource_t;

							segment_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collection_t* p__parent = 0, qt_installer_framework_t* p__root = 0);

						private:
							void _read();

						public:
							~segment_t();

							class resource_t : public kaitai::kstruct {

							public:

								resource_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collection_t::segment_t* p__parent = 0, qt_installer_framework_t* p__root = 0);

							private:
								void _read();

							public:
								~resource_t();

							private:
								string_t* m_name;
								range_t* m_segment;
								qt_installer_framework_t* m__root;
								qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collection_t::segment_t* m__parent;

							public:
								string_t* name() const { return m_name; }
								range_t* segment() const { return m_segment; }
								qt_installer_framework_t* _root() const { return m__root; }
								qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collection_t::segment_t* _parent() const { return m__parent; }
							};

						private:
							uint64_t m_count;
							std::vector<resource_t*>* m_resources;
							qt_installer_framework_t* m__root;
							qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collection_t* m__parent;

						public:
							uint64_t count() const { return m_count; }
							std::vector<resource_t*>* resources() const { return m_resources; }
							qt_installer_framework_t* _root() const { return m__root; }
							qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collection_t* _parent() const { return m__parent; }
						};

					private:
						bool f_segment;
						segment_t* m_segment;

					public:
						segment_t* segment();

					private:
						string_t* m_name;
						range_t* m_segment_range;
						qt_installer_framework_t* m__root;
						qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t* m__parent;
						std::string m__raw_segment;
						kaitai::kstream* m__io__raw_segment;

					public:
						string_t* name() const { return m_name; }
						range_t* segment_range() const { return m_segment_range; }
						qt_installer_framework_t* _root() const { return m__root; }
						qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t* _parent() const { return m__parent; }
						std::string _raw_segment() const { return m__raw_segment; }
						kaitai::kstream* _io__raw_segment() const { return m__io__raw_segment; }
					};

				private:
					int64_t m_count;
					std::vector<collection_t*>* m_collections;
					qt_installer_framework_t* m__root;
					qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t* m__parent;

				public:
					int64_t count() const { return m_count; }
					std::vector<collection_t*>* collections() const { return m_collections; }
					qt_installer_framework_t* _root() const { return m__root; }
					qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t* _parent() const { return m__parent; }
				};

			private:
				bool f_collections;
				collections_t* m_collections;

			public:
				collections_t* collections();

			private:
				bool f_operations;
				operations_t* m_operations;

			public:
				operations_t* operations();

			private:
				range_t* m_resource_collections_segment;
				std::vector<range_t*>* m_meta_resource_segments;
				range_t* m_operations_segment;
				qt_installer_framework_t* m__root;
				qt_installer_framework_t::header_t::binary_descriptor_t* m__parent;
				std::string m__raw_collections;
				kaitai::kstream* m__io__raw_collections;
				std::string m__raw_operations;
				kaitai::kstream* m__io__raw_operations;

			public:
				range_t* resource_collections_segment() const { return m_resource_collections_segment; }
				std::vector<range_t*>* meta_resource_segments() const { return m_meta_resource_segments; }
				range_t* operations_segment() const { return m_operations_segment; }
				qt_installer_framework_t* _root() const { return m__root; }
				qt_installer_framework_t::header_t::binary_descriptor_t* _parent() const { return m__parent; }
				std::string _raw_collections() const { return m__raw_collections; }
				kaitai::kstream* _io__raw_collections() const { return m__io__raw_collections; }
				std::string _raw_operations() const { return m__raw_operations; }
				kaitai::kstream* _io__raw_operations() const { return m__io__raw_operations; }
			};

		private:
			bool f_size_of_segment_descriptor;
			int64_t m_size_of_segment_descriptor;

		public:
			int64_t size_of_segment_descriptor();

		private:
			bool f_segments_descriptor;
			segments_descriptor_t* m_segments_descriptor;

		public:
			segments_descriptor_t* segments_descriptor();

		private:
			bool f_end_of_exectuable;
			int64_t m_end_of_exectuable;

		public:
			int64_t end_of_exectuable();

		private:
			int64_t m_resources_count;
			int64_t m_binary_content_size;
			marker_identifier_t* m_marker;
			qt_installer_framework_t* m__root;
			qt_installer_framework_t::header_t* m__parent;
			std::string m__raw_segments_descriptor;
			kaitai::kstream* m__io__raw_segments_descriptor;

		public:

			/**
			 * read it, but deliberately not used
			 */
			int64_t resources_count() const { return m_resources_count; }
			int64_t binary_content_size() const { return m_binary_content_size; }
			marker_identifier_t* marker() const { return m_marker; }
			qt_installer_framework_t* _root() const { return m__root; }
			qt_installer_framework_t::header_t* _parent() const { return m__parent; }
			std::string _raw_segments_descriptor() const { return m__raw_segments_descriptor; }
			kaitai::kstream* _io__raw_segments_descriptor() const { return m__io__raw_segments_descriptor; }
		};

	private:
		bool f_other_stuff_size;
		int64_t m_other_stuff_size;

	public:

		/**
		 * meta count, offset/length collection index, marker, cookie...
		 */
		int64_t other_stuff_size();

	private:
		bool f_binary_descriptor_offset;
		int64_t m_binary_descriptor_offset;

	public:
		int64_t binary_descriptor_offset();

	private:
		bool f_binary_descriptor;
		binary_descriptor_t* m_binary_descriptor;

	public:
		binary_descriptor_t* binary_descriptor();

	private:
		uint64_t m_meta_resources_count;
		std::vector<uint64_t>* m_unkn;
		cookie_identifier_t* m_cookie;
		qt_installer_framework_t* m__root;
		qt_installer_framework_t* m__parent;
		std::string m__raw_binary_descriptor;
		kaitai::kstream* m__io__raw_binary_descriptor;

	public:
		uint64_t meta_resources_count() const { return m_meta_resources_count; }
		std::vector<uint64_t>* unkn() const { return m_unkn; }
		cookie_identifier_t* cookie() const { return m_cookie; }
		qt_installer_framework_t* _root() const { return m__root; }
		qt_installer_framework_t* _parent() const { return m__parent; }
		std::string _raw_binary_descriptor() const { return m__raw_binary_descriptor; }
		kaitai::kstream* _io__raw_binary_descriptor() const { return m__io__raw_binary_descriptor; }
	};

private:
	bool f_end_of_binary_content;
	int64_t m_end_of_binary_content;

public:
	int64_t end_of_binary_content();

private:
	bool f_header;
	header_t* m_header;

public:
	header_t* header();

private:
	uint64_t m_magic_cookie_offset;
	qt_installer_framework_t* m__root;
	kaitai::kstruct* m__parent;

public:
	uint64_t magic_cookie_offset() const { return m_magic_cookie_offset; }
	qt_installer_framework_t* _root() const { return m__root; }
	kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // QT_INSTALLER_FRAMEWORK_H_
