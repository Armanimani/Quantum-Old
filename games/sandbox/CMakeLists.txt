message("Quantum: Configuring game-sandbox...")

set(QUANTUM_SANDBOX_SOURCES
	entryPoint.cpp
	application/Sandbox.cpp
)

# Executable
add_executable(Quantum-game-sandbox ${QUANTUM_SANDBOX_SOURCES})

# Dependencies
target_link_libraries(Quantum-game-sandbox Quantum-core)