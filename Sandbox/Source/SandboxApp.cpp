#include <Jem.h>

using namespace Jem;

class Sandbox : public Game {
public:
	Sandbox() {
		mousePos = Input::GetMousePosition();
	}

	void ScreenClearColourDemo(double deltaTime) {
		static int i = 0;
		static double range = 500;

		if (i >= range) i = 0;  range = 500;
		i += int(((double(1) + 100.0f) * deltaTime));

		//we want to normalize ratio so that it fits in to 6 regions
		//where each region is 256 units long
		int normalized = int(i / range * 256 * 6);

		//find the distance to the start of the closest region
		int x = normalized % 256;

		int red = 0, grn = 0, blu = 0;
		switch (normalized / 256)
		{
		case 0: red = 255;      grn = x;        blu = 0;       break;//red
		case 1: red = 255 - x;  grn = 255;      blu = 0;       break;//yellow
		case 2: red = 0;        grn = 255;      blu = x;       break;//green
		case 3: red = 0;        grn = 255 - x;  blu = 255;     break;//cyan
		case 4: red = x;        grn = 0;        blu = 255;     break;//blue
		case 5: red = 255;      grn = 0;        blu = 255 - x; break;//magenta
		}
		Renderer::SetClearColour(red, grn, blu);
	}

	void Update(double deltaTime) {
		ScreenClearColourDemo(deltaTime);

		std::pair<int, int> newMousePos = Input::GetMousePosition();

		if (mousePos != newMousePos) JEM_MESSAGE("Mouse moved to ", newMousePos.first, ", ", newMousePos.second);
		if (Input::IsMouseButtonPressed(MouseCode::JEM_BUTTON_LEFT))   JEM_WARNING("Left mouse button pressed");
		if (Input::IsMouseButtonPressed(MouseCode::JEM_BUTTON_MIDDLE)) JEM_WARNING("Middle mouse button pressed");
		if (Input::IsMouseButtonPressed(MouseCode::JEM_BUTTON_RIGHT))  JEM_WARNING("Right mouse button pressed");
		if (Input::IsMouseButtonPressed(MouseCode::JEM_BUTTON_X1))     JEM_WARNING("X1 mouse button pressed");
		if (Input::IsMouseButtonPressed(MouseCode::JEM_BUTTON_X2))     JEM_WARNING("X2 mouse button pressed");

		mousePos = Input::GetMousePosition();
	}

private:
	std::pair<int, int> mousePos;
};

namespace Jem {
	Game* CreateGame() {
		return new Sandbox();
	}
}