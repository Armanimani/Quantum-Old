message("Quantum: Configuring engine-core...") 

file(GLOB QUANTUM_ENGINE_CORE_HEADERS_ "*.hpp")
file(GLOB QUANTUM_ENGINE_CORE_SOURCES_ "*.cpp")

add_library(Quantum-core STATIC 
	${QUANTUM_ENGINE_CORE_HEADERS_} 
	${QUANTUM_ENGINE_CORE_SOURCES_}
)