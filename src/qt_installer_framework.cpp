// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include <memory>
#include "qt_installer_framework.h"
#include "kaitai/exceptions.h"

qt_installer_framework_t::qt_installer_framework_t(uint64_t p_magic_cookie_offset, kaitai::kstream* p__io, kaitai::kstruct* p__parent, qt_installer_framework_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = this;
	m_magic_cookie_offset = p_magic_cookie_offset;
	m_header = 0;
	f_end_of_binary_content = false;
	f_header = false;
	_read();
}

void qt_installer_framework_t::_read() {
}

qt_installer_framework_t::~qt_installer_framework_t() {
	if (f_header) {
		delete m_header;
	}
}

qt_installer_framework_t::array_t::array_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, qt_installer_framework_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = p__root;
	_read();
}

void qt_installer_framework_t::array_t::_read() {
	m_size = m__io->read_u8le();
	m_value = m__io->read_bytes(size());
}

qt_installer_framework_t::array_t::~array_t() {
}

qt_installer_framework_t::string_t::string_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, qt_installer_framework_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = p__root;
	_read();
}

void qt_installer_framework_t::string_t::_read() {
	m_size = m__io->read_u8le();
	m_value = kaitai::kstream::bytes_to_str(m__io->read_bytes(size()), std::string("utf-8"));
}

qt_installer_framework_t::string_t::~string_t() {
}

qt_installer_framework_t::header_t::header_t(kaitai::kstream* p__io, qt_installer_framework_t* p__parent, qt_installer_framework_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = p__root;
	m_unkn = 0;
	m_cookie = 0;
	m_binary_descriptor = 0;
	m__io__raw_binary_descriptor = 0;
	f_other_stuff_size = false;
	f_binary_descriptor_offset = false;
	f_binary_descriptor = false;
	_read();
}

void qt_installer_framework_t::header_t::_read() {
	m_meta_resources_count = m__io->read_u8le();
	int l_unkn = 2;
	m_unkn = new std::vector<uint64_t>();
	m_unkn->reserve(l_unkn);
	for (int i = 0; i < l_unkn; i++) {
		m_unkn->push_back(m__io->read_u8le());
	}
	m_cookie = new cookie_identifier_t(m__io, this, m__root);
}

qt_installer_framework_t::header_t::~header_t() {
	delete m_unkn;
	delete m_cookie;
	if (f_binary_descriptor) {
		delete m__io__raw_binary_descriptor;
		delete m_binary_descriptor;
	}
}

qt_installer_framework_t::header_t::marker_identifier_t::marker_identifier_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t::binary_descriptor_t* p__parent, qt_installer_framework_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = p__root;
	_read();
}

void qt_installer_framework_t::header_t::marker_identifier_t::_read() {
	m_type = static_cast<qt_installer_framework_t::header_t::marker_identifier_t::type_t>(m__io->read_u1());
	m_signature = m__io->read_bytes(3);
	if (!(signature() == std::string("\x32\x02\x12", 3))) {
		throw kaitai::validation_not_equal_error<std::string>(std::string("\x32\x02\x12", 3), signature(), _io(), std::string("/types/header/types/marker_identifier/seq/1"));
	}
}

qt_installer_framework_t::header_t::marker_identifier_t::~marker_identifier_t() {
}

qt_installer_framework_t::header_t::cookie_identifier_t::cookie_identifier_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t* p__parent, qt_installer_framework_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = p__root;
	_read();
}

void qt_installer_framework_t::header_t::cookie_identifier_t::_read() {
	m_type = static_cast<qt_installer_framework_t::header_t::cookie_identifier_t::type_t>(m__io->read_u1());
	m_signature = m__io->read_bytes(7);
	if (!(signature() == std::string("\x68\xD6\x99\x1C\x0A\x63\xC2", 7))) {
		throw kaitai::validation_not_equal_error<std::string>(std::string("\x68\xD6\x99\x1C\x0A\x63\xC2", 7), signature(), _io(), std::string("/types/header/types/cookie_identifier/seq/1"));
	}
}

qt_installer_framework_t::header_t::cookie_identifier_t::~cookie_identifier_t() {
}

qt_installer_framework_t::header_t::range_t::range_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, qt_installer_framework_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = p__root;
	f_start = false;
	_read();
}

void qt_installer_framework_t::header_t::range_t::_read() {
	m_start_read = m__io->read_s8le();
	m_size = m__io->read_s8le();
}

qt_installer_framework_t::header_t::range_t::~range_t() {
}

int64_t qt_installer_framework_t::header_t::range_t::start() {
	if (f_start)
		return m_start;
	m_start = (_root()->header()->binary_descriptor()->end_of_exectuable() + start_read());
	f_start = true;
	return m_start;
}

qt_installer_framework_t::header_t::binary_descriptor_t::binary_descriptor_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t* p__parent, qt_installer_framework_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = p__root;
	m_marker = 0;
	m_segments_descriptor = 0;
	m__io__raw_segments_descriptor = 0;
	f_size_of_segment_descriptor = false;
	f_segments_descriptor = false;
	f_end_of_exectuable = false;
	_read();
}

void qt_installer_framework_t::header_t::binary_descriptor_t::_read() {
	m_resources_count = m__io->read_s8le();
	m_binary_content_size = m__io->read_s8le();
	m_marker = new marker_identifier_t(m__io, this, m__root);
}

qt_installer_framework_t::header_t::binary_descriptor_t::~binary_descriptor_t() {
	delete m_marker;
	if (f_segments_descriptor) {
		delete m__io__raw_segments_descriptor;
		delete m_segments_descriptor;
	}
}

qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::segments_descriptor_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t::binary_descriptor_t* p__parent, qt_installer_framework_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = p__root;
	m_resource_collections_segment = 0;
	m_meta_resource_segments = 0;
	m_operations_segment = 0;
	m_collections = 0;
	m__io__raw_collections = 0;
	m_operations = 0;
	m__io__raw_operations = 0;
	f_collections = false;
	f_operations = false;
	_read();
}

void qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::_read() {
	m_resource_collections_segment = new range_t(m__io, this, m__root);
	int l_meta_resource_segments = _parent()->_parent()->meta_resources_count();
	m_meta_resource_segments = new std::vector<range_t*>();
	m_meta_resource_segments->reserve(l_meta_resource_segments);
	for (int i = 0; i < l_meta_resource_segments; i++) {
		m_meta_resource_segments->push_back(new range_t(m__io, this, m__root));
	}
	m_operations_segment = new range_t(m__io, this, m__root);
}

qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::~segments_descriptor_t() {
	delete m_resource_collections_segment;
	for (std::vector<range_t*>::iterator it = m_meta_resource_segments->begin(); it != m_meta_resource_segments->end(); ++it) {
		delete *it;
	}
	delete m_meta_resource_segments;
	delete m_operations_segment;
	if (f_collections) {
		delete m__io__raw_collections;
		delete m_collections;
	}
	if (f_operations) {
		delete m__io__raw_operations;
		delete m_operations;
	}
}

qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::operations_t::operations_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t* p__parent, qt_installer_framework_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = p__root;
	m_operations = 0;
	_read();
}

void qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::operations_t::_read() {
	m_count = m__io->read_u8le();
	int l_operations = count();
	m_operations = new std::vector<operation_t*>();
	m_operations->reserve(l_operations);
	for (int i = 0; i < l_operations; i++) {
		m_operations->push_back(new operation_t(m__io, this, m__root));
	}
	m_reserved = m__io->read_u8le();
}

qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::operations_t::~operations_t() {
	for (std::vector<operation_t*>::iterator it = m_operations->begin(); it != m_operations->end(); ++it) {
		delete *it;
	}
	delete m_operations;
}

qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::operations_t::operation_t::operation_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::operations_t* p__parent, qt_installer_framework_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = p__root;
	m_name = 0;
	m_xml = 0;
	_read();
}

void qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::operations_t::operation_t::_read() {
	m_name = new string_t(m__io, this, m__root);
	m_xml = new string_t(m__io, this, m__root);
}

qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::operations_t::operation_t::~operation_t() {
	delete m_name;
	delete m_xml;
}

qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collections_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t* p__parent, qt_installer_framework_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = p__root;
	m_collections = 0;
	_read();
}

void qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::_read() {
	m_count = m__io->read_s8le();
	int l_collections = count();
	m_collections = new std::vector<collection_t*>();
	m_collections->reserve(l_collections);
	for (int i = 0; i < l_collections; i++) {
		m_collections->push_back(new collection_t(m__io, this, m__root));
	}
}

qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::~collections_t() {
	for (std::vector<collection_t*>::iterator it = m_collections->begin(); it != m_collections->end(); ++it) {
		delete *it;
	}
	delete m_collections;
}

qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collection_t::collection_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t* p__parent, qt_installer_framework_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = p__root;
	m_name = 0;
	m_segment_range = 0;
	m_segment = 0;
	m__io__raw_segment = 0;
	f_segment = false;
	_read();
}

void qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collection_t::_read() {
	m_name = new string_t(m__io, this, m__root);
	m_segment_range = new range_t(m__io, this, m__root);
}

qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collection_t::~collection_t() {
	delete m_name;
	delete m_segment_range;
	if (f_segment) {
		delete m__io__raw_segment;
		delete m_segment;
	}
}

qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collection_t::segment_t::segment_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collection_t* p__parent, qt_installer_framework_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = p__root;
	m_resources = 0;
	_read();
}

void qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collection_t::segment_t::_read() {
	m_count = m__io->read_u8le();
	int l_resources = count();
	m_resources = new std::vector<resource_t*>();
	m_resources->reserve(l_resources);
	for (int i = 0; i < l_resources; i++) {
		m_resources->push_back(new resource_t(m__io, this, m__root));
	}
}

qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collection_t::segment_t::~segment_t() {
	for (std::vector<resource_t*>::iterator it = m_resources->begin(); it != m_resources->end(); ++it) {
		delete *it;
	}
	delete m_resources;
}

qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collection_t::segment_t::resource_t::resource_t(kaitai::kstream* p__io, qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collection_t::segment_t* p__parent, qt_installer_framework_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = p__root;
	m_name = 0;
	m_segment = 0;
	_read();
}

void qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collection_t::segment_t::resource_t::_read() {
	m_name = new string_t(m__io, this, m__root);
	m_segment = new range_t(m__io, this, m__root);
}

qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collection_t::segment_t::resource_t::~resource_t() {
	delete m_name;
	delete m_segment;
}

qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collection_t::segment_t* qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t::collection_t::segment() {
	if (f_segment)
		return m_segment;
	kaitai::kstream *io = _root()->_io();
	std::streampos _pos = io->pos();
	io->seek(segment_range()->start());
	m__raw_segment = io->read_bytes(segment_range()->size());
	m__io__raw_segment = new kaitai::kstream(m__raw_segment);
	m_segment = new segment_t(m__io__raw_segment, this, m__root);
	io->seek(_pos);
	f_segment = true;
	return m_segment;
}

qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections_t* qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::collections() {
	if (f_collections)
		return m_collections;
	kaitai::kstream *io = _root()->_io();
	std::streampos _pos = io->pos();
	io->seek(resource_collections_segment()->start());
	m__raw_collections = io->read_bytes(resource_collections_segment()->size());
	m__io__raw_collections = new kaitai::kstream(m__raw_collections);
	m_collections = new collections_t(m__io__raw_collections, this, m__root);
	io->seek(_pos);
	f_collections = true;
	return m_collections;
}

qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::operations_t* qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t::operations() {
	if (f_operations)
		return m_operations;
	kaitai::kstream *io = _root()->_io();
	std::streampos _pos = io->pos();
	io->seek(operations_segment()->start());
	m__raw_operations = io->read_bytes(operations_segment()->size());
	m__io__raw_operations = new kaitai::kstream(m__raw_operations);
	m_operations = new operations_t(m__io__raw_operations, this, m__root);
	io->seek(_pos);
	f_operations = true;
	return m_operations;
}

int64_t qt_installer_framework_t::header_t::binary_descriptor_t::size_of_segment_descriptor() {
	if (f_size_of_segment_descriptor)
		return m_size_of_segment_descriptor;
	m_size_of_segment_descriptor = ((_parent()->meta_resources_count() + 2) * 16);
	f_size_of_segment_descriptor = true;
	return m_size_of_segment_descriptor;
}

qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor_t* qt_installer_framework_t::header_t::binary_descriptor_t::segments_descriptor() {
	if (f_segments_descriptor)
		return m_segments_descriptor;
	kaitai::kstream *io = _root()->_io();
	std::streampos _pos = io->pos();
	io->seek((_parent()->binary_descriptor_offset() - size_of_segment_descriptor()));
	m__raw_segments_descriptor = io->read_bytes(size_of_segment_descriptor());
	m__io__raw_segments_descriptor = new kaitai::kstream(m__raw_segments_descriptor);
	m_segments_descriptor = new segments_descriptor_t(m__io__raw_segments_descriptor, this, m__root);
	io->seek(_pos);
	f_segments_descriptor = true;
	return m_segments_descriptor;
}

int64_t qt_installer_framework_t::header_t::binary_descriptor_t::end_of_exectuable() {
	if (f_end_of_exectuable)
		return m_end_of_exectuable;
	m_end_of_exectuable = (_parent()->_root()->end_of_binary_content() - binary_content_size());
	f_end_of_exectuable = true;
	return m_end_of_exectuable;
}

int64_t qt_installer_framework_t::header_t::other_stuff_size() {
	if (f_other_stuff_size)
		return m_other_stuff_size;
	m_other_stuff_size = (4 * 8);
	f_other_stuff_size = true;
	return m_other_stuff_size;
}

int64_t qt_installer_framework_t::header_t::binary_descriptor_offset() {
	if (f_binary_descriptor_offset)
		return m_binary_descriptor_offset;
	m_binary_descriptor_offset = (_root()->end_of_binary_content() - other_stuff_size());
	f_binary_descriptor_offset = true;
	return m_binary_descriptor_offset;
}

qt_installer_framework_t::header_t::binary_descriptor_t* qt_installer_framework_t::header_t::binary_descriptor() {
	if (f_binary_descriptor)
		return m_binary_descriptor;
	kaitai::kstream *io = _root()->_io();
	std::streampos _pos = io->pos();
	io->seek(binary_descriptor_offset());
	m__raw_binary_descriptor = io->read_bytes(20);
	m__io__raw_binary_descriptor = new kaitai::kstream(m__raw_binary_descriptor);
	m_binary_descriptor = new binary_descriptor_t(m__io__raw_binary_descriptor, this, m__root);
	io->seek(_pos);
	f_binary_descriptor = true;
	return m_binary_descriptor;
}

int64_t qt_installer_framework_t::end_of_binary_content() {
	if (f_end_of_binary_content)
		return m_end_of_binary_content;
	m_end_of_binary_content = (magic_cookie_offset() + 8);
	f_end_of_binary_content = true;
	return m_end_of_binary_content;
}

qt_installer_framework_t::header_t* qt_installer_framework_t::header() {
	if (f_header)
		return m_header;
	std::streampos _pos = m__io->pos();
	m__io->seek((end_of_binary_content() - 32));
	m_header = new header_t(m__io, this, m__root);
	m__io->seek(_pos);
	f_header = true;
	return m_header;
}
