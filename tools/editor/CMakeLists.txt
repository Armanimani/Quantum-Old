message("Quantum: Configuring editor...") 

file(GLOB QUANTUM_EDITOR_HEADERS_ "*.hpp")
file(GLOB QUANTUM_EDITOR_SOURCES_ "*.cpp")

add_executable(Quantum_editor ${QUANTUM_EDITOR_SOURCES_})