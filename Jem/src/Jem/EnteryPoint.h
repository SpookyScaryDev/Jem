#pragma once

#include <Jem/Application/Application.h>
#include <Jem/Log/Log.h>

namespace Jem {
	extern Application* CreateApplication();
}

int main(int argc, char **argv) {
	Jem::Log::init();

	auto applicaton = Jem::CreateApplication();
	applicaton->run();
	delete applicaton;

	Jem::Log::shutdown();

	return 0;
}