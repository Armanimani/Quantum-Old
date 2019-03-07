message("Quantum: Configuring unit tests...")

# External: googletest
set(QUANTUM_GOOGLETEST_DIR ${QUANTUM_EXTERNAL_LIBRARY_DIRECTORY}/googletest)
if(NOT EXISTS ${QUANTUM_GOOGLETEST_DIR})
	find_package(Git REQUIRED)
	execute_process(COMMAND ${GIT_EXECUTABLE} clone https://github.com/google/googletest ${QUANTUM_GOOGLETEST_DIR})
endif()

# googletest -> gtest 
set(QUANTUM_GOOGLETEST_SOURCE ${QUANTUM_GOOGLETEST_DIR}/googletest/src/gtest-all.cc)
add_library(gtest STATIC ${QUANTUM_GOOGLETEST_SOURCE})

# googletest ->gtest_main
set(QUANTUM_GOOGLETEST_MAIN_SOURCE ${QUANTUM_GOOGLETEST_DIR}/googletest/src/gtest_main.cc)
add_library(gtest_main STATIC ${QUANTUM_GOOGLETEST_MAIN_SOURCE})

# googletest: include
include_directories(${QUANTUM_GOOGLETEST_DIR}/googletest/include ${QUANTUM_GOOGLETEST_DIR}/googletest)

# unit test files
set(QUANTUM_UNIT_TESTS_ENGINE_SOURCES 
	engine/test.cpp
)

add_executable(Quantum-unitTests ${QUANTUM_UNIT_TESTS_ENGINE_SOURCES})

target_link_libraries(Quantum-unitTests gtest gtest_main)