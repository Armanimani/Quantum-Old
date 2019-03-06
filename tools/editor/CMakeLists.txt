message("Quantum: Configuring editor...") 

file(GLOB QUANTUM_EDITOR_HEADERS_ "*.hpp")
file(GLOB QUANTUM_EDITOR_SOURCES_ "*.cpp")

add_executable(Quantum-editor ${QUANTUM_EDITOR_SOURCES_})