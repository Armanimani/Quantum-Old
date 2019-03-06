#pragma once

#include "Application.hpp"
#include <memory>

extern std::unique_ptr<Quantum::core::Application> createApplication();

int main(int argc, char** argv)
{
	auto app = createApplication();
	app->run();
}