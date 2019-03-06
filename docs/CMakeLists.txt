message("Quantum: Configuring docs...")

# External: doxygen
set(QUANTUM_DOXYGEN_DIR ${QUANTUM_EXTERNAL_LIBRARY_DIRECTORY}/doxygen)
if(NOT EXISTS ${QUANTUM_DOXYGEN_DIR})
	find_package(Git REQUIRED)
	execute_process(COMMAND ${GIT_EXECUTABLE} clone https://github.com/doxygen/doxygen.git ${QUANTUM_DOXYGEN_DIR})
endif()

# Doxygen configuration
set(QUANTUM_DOXYGEN_INPUT DoxyFile)
set(QUANTUM_DOXYGEN_OUTPUT ${CMAKE_CURRENT_DIR}/documentation)

configure_file(${QUANTUM_DOXYGEN_INPUT} ${QUANTUM_DOXYGEN_OUTPUT} @ONLY)

add_custom_target(Quantum-docs 
	COMMAND ${DOXYGEN_EXECUTABLE} ${QUANTUM_DOXYGEN_OUTPUT}
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMENT "Generating API documentation with Doxygen"
	VERBATIM
)