message("Quantum: Configuring engine-core...") 

set(QUANTUM_ENGINE_CORE_SOURCES
	entryPoint.cpp
	application/Application.cpp
)

add_library(Quantum-core STATIC 
	${QUANTUM_ENGINE_CORE_SOURCES} 
)