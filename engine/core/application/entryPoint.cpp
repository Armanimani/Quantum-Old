#pragma once

#include "Application.hpp"
#include <memory>

extern std::unique_ptr<Quantum::core::Application> createApplication();

#ifdef QUANTUM_TARGET_PLATFORM_WINDOWS 
	int main(int argc, char** argv)
	{
		auto app = createApplication();
		app->run();
	}
#elif QUANTUM_TARGET_PLATFORM_LINUX
	#error The linux platform is not supported yet!
#elif QUANTUM_TARGET_PLATFORM_MACOS
	#error The macOS platform is not supported yet!
#else
	#error Unknown plateform!
#endif