message("Quantum: Configuring quantum-editor...")

set(QUANTUM_EDITOR_SOURCES
	entryPoint.cpp
	application/Editor.cpp
)

include_directories(${CMAKE_CURRENT_DIRECTORY})

# Executable
add_executable(Quantum-editor
	${QUANTUM_EDITOR_SOURCES} 
)

# Dependencies
target_link_libraries(Quantum-editor Quantum-core)