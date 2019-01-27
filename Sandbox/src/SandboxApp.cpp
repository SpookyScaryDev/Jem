#include <Jem.h>


class Sandbox : public Jem::Application {

};

Jem::Application* Jem::CreateApplication() {
	return new Sandbox();
}