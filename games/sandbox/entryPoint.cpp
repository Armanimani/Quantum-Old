#include "application/Sandbox.hpp"

#include <memory>

std::unique_ptr<Quantum::core::Application> createApplication()
{
	return std::make_unique<Quantum::sandbox::Sandbox>();
}