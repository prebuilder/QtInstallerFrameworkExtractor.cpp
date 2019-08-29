CMAKE_MINIMUM_REQUIRED(VERSION 3.14)
set(CMake_Misc_Dir "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMake_Misc_Dir}")

include(Hardening)
include(FetchContent)
include(DownloadCLI11)
PROJECT(QtInstallerFrameworkExtractor)

downloadCLI11IfNeeded("CLI11")

set(CMAKE_USE_RELATIVE_PATHS TRUE)
set(Source_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(kaitai_struct_cpp_runtime_DIR "${CMAKE_CURRENT_SOURCE_DIR}/kaitai_struct_cpp_stl_runtime")

file(GLOB_RECURSE SRCFILES "${Source_dir}/*.c" "${Source_dir}/*.cpp")
if(MSVC_IDE)
	file(GLOB_RECURSE HDRFILES "${Source_dir}/*.h")
endif()

add_subdirectory("${kaitai_struct_cpp_runtime_DIR}")

add_executable(QtInstallerFrameworkExtractor "${SRCFILES}")
target_link_libraries(QtInstallerFrameworkExtractor kaitai_struct_cpp_stl_runtime)
target_include_directories(QtInstallerFrameworkExtractor PUBLIC "${kaitai_struct_cpp_runtime_DIR}" "${CLI11_INCLUDE_DIR}")

set_property(TARGET QtInstallerFrameworkExtractor PROPERTY CXX_STANDARD 20)
set_property(TARGET QtInstallerFrameworkExtractor PROPERTY PREFIX "")
harden(QtInstallerFrameworkExtractor)
