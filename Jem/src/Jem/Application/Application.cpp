#include "Application.h"
#include <Jem/Log/Log.h>
// TODO: pch
#include <iostream>

namespace Jem {

	Application::Application() {}
	Application::~Application() {}

	void Application::run() {
		JEM_CORE_MESSAGE("Running Application");
		std::cin.get();
	}

}