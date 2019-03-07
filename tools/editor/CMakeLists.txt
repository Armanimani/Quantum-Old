message("Quantum: Configuring quantum-editor...")

file(GLOB QUANTUM_EDITOR_HEADERS_ "*.hpp")
file(GLOB QUANTUM_EDITOR_SOURCES_ "*.cpp")
file(GLOB QUANTUM_EDITOR_APPLICATION_SOURCES "application/*.?pp")

include_directories(${CMAKE_CURRENT_DIRECTORY})

# Executable
add_executable(Quantum-editor
	${QUANTUM_EDITOR_HEADERS_} 
	${QUANTUM_EDITOR_SOURCES_}
	${QUANTUM_EDITOR_APPLICATION_SOURCES}
)

# Dependencies
target_link_libraries(Quantum-editor Quantum-core)