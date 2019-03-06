message("Quantum: Configuring game-sandbox...")

file(GLOB QUANTUM_SANDBOX_HEADERS_ "*.hpp")
file(GLOB QUANTUM_SANDBOX_SOURCES_ "*.cpp")

# Executable
add_executable(Quantum-game-sandbox ${QUANTUM_SANDBOX_HEADERS_} ${QUANTUM_SANDBOX_SOURCES_})

# Dependencies
target_link_libraries(Quantum-game-sandbox Quantum-core)