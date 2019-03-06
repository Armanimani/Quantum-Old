cmake_minimum_required(VERSION 3.12)

project(Quantum)

message("Quantum: Configuring...")

# Version information
set(QUANTUM_VERSION_MAJOR "0")
set(QUANTUM_VERSION_MINOR "0")
set(QUANTUM_VERSION_PATCH "0")
set(QUANTUM_VERSION "${QUANTUM_VERSION_MAJOR}.${QUANTUM_VERSION_MINOR}.${QUANTUM_VERSION_PATCH}")
set(VERSION ${QUANTUM_VERSION})

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    add_compile_definitions(QUANTUM_BUILD_DEBUG)
	message("Quantum: Building debug mode...")
elseif (CMAKE_BUILD_TYPE MATCHES "Release")
	add_compile_definitions(QUANTUM_BUILD_RELEASE)
	message("Quantum: Building release mode...")
endif()

# C++ compiler
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)

# Determine platform
if (CMAKE_SYSTEM_NAME MATCHES "Windows")
	set(QUANTUM_TARGET_PLATFORM_WINDOWS TRUE)
	set(QUANTUM_TARGET_PLATFORM_NAME "Windows")
	add_compile_definitions(QUANTUM_TARGET_PLATFORM_WINDOWS)
elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
	set(QUANTUM_TARGET_PLATFORM_LINUX TRUE)
	set(QUANTUM_TARGET_PLATFORM_NAME "Linux")
	add_compile_definitions(QUANTUM_TARGET_PLATFORM_LINUX)
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")
	set(QUANTUM_TARGET_PLATFORM_MACOS TRUE)
	set(QUANTUM_TARGET_PLATFORM_NAME "MacOS")
	add_compile_definitions(QUANTUM_TARGET_PLATFORM_MACOS)
else()
	message(FATAL_ERROR "Quantum engine is not compatible with target platform = ${CMAKE_SYSTEM_NAME}")
endif()

message("Quantum: \tPlatform = ${QUANTUM_TARGET_PLATFORM_NAME}")

# Determine architecture
if (((CMAKE_SYSTEM_PROCESSOR MATCHES "AMD64") OR (CMAKE_SYSTEM_PROCESSOR MATCHES "x86")) AND CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(QUANTUM_TARGET_ARCHITECTURE_X64 TRUE)
	set(QUANTUM_TARGET_ARCHITECTURE_NAME "x86-64")
	add_compile_definitions(QUANTUM_TARGET_ARCHITECTURE_X64)
elseif ((CMAKE_SYSTEM_PROCESSOR MATCHES "AMD64") AND (CMAKE_SIZEOF_VOID_P EQUAL 4))
	set(QUANTUM_TARGET_ARCHITECTURE_X86 TRUE)
	set(QUANTUM_TARGET_ARCHITECTURE_NAME "x86")
	add_compile_definitions(QUANTUM_TARGET_ARCHITECTURE_X86)
else()
	message(FATAL_ERROR "Quantum engine is not compatible with target architecture = ${CMAKE_SYSTEM_PROCESSOR}")
endif()

message("Quantum: \tArchitencture = ${QUANTUM_TARGET_ARCHITECTURE_NAME}")

# Determine C++ compiler
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	set(QUANTUM_TARGET_CXX_COMPILER_MSVC TRUE)
	set(QUANTUM_TARGET_CXX_COMPILER_NAME "MSVC")
	add_compile_definitions(QUANTUM_TARGET_CXX_COMPILER_MSVC)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set(QUANTUM_TARGET_CXX_COMPILER_CLANG TRUE)
	set(QUANTUM_TARGET_CXX_COMPILER_NAME "Clang")
	add_compile_definitions(QUANTUM_TARGET_CXX_COMPILER_CLANG)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
	set(QUANTUM_TARGET_CXX_COMPILER_GNU TRUE)
	set(QUANTUM_TARGET_CXX_COMPILER_NAME "GNU")
	add_compile_definitions(QUANTUM_TARGET_CXX_COMPILER_GNU)
else()
	message(FATAL_ERROR "Quantum engine is not compatible with C++ compiler = ${CMAKE_CXX_COMPILER_ID}")
endif()

message("Quantum: \tCompiler(C++) = ${QUANTUM_TARGET_CXX_COMPILER_NAME}")

# set directories
set(QUANTUM_BIN_DIRECTORY "bin")
set(QUANTUM_LIB_SUBDIRECTORY "lib")
set(QUANTUM_BUILD_SUBDIRECTORY "build")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/${QUANTUM_BIN_DIRECTORY}/${QUANTUM_LIB_SUBDIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/${QUANTUM_BIN_DIRECTORY}/${QUANTUM_LIB_SUBDIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/${QUANTUM_BIN_DIRECTORY})

set(QUANTUM_EXTERNAL_LIBRARY_DIRECTORY ${CMAKE_SOURCE_DIR}/external)

# Add include directories
include_directories("${CMAKE_CURRENT_LIST_DIR}/engine")

# Add subdirectories
add_subdirectory(engine)
add_subdirectory(games)
add_subdirectory(tests)
add_subdirectory(tools)
add_subdirectory(docs)