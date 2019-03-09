#include <Jem.h>


class Sandbox : public Jem::Application {

};

int main(int argc, char **argv) {
	Jem::Log::Init();                  // TODO: Init function / constructor in application.

	Sandbox* sandbox = new Sandbox();
	sandbox->Run();

	delete sandbox;

	Jem::Log::Shutdown();

	return 0;
}