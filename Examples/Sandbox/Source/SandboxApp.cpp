#include <Jem.h>

class Sandbox : public Jem::Game {

};

Jem::Game* Jem::CreateGame() {
	return new Sandbox();
}