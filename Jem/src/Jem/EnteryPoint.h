#pragma once

#include <Jem/Application/Application.h>
#include <Jem/Log/Log.h>

namespace Jem {
	extern Application* CreateApplication();
}

int main(int argc, char **argv) {
	Jem::Log::Init();

	auto applicaton = Jem::CreateApplication();
	applicaton->Run();

	delete applicaton;

	Jem::Log::Shutdown();

	return 0;
}