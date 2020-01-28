#pragma once

#include <Core/StringID/StringID.h>
#include <Core/Window/Window.h>

namespace Jem {
	// A base app class.
	class Game {
	public:
		                    Game(const char* name = "Jem 2D Game Engine : Better Than ID Tech 7!",
								int width = 500,
								int height = 500);
		virtual             ~Game();

		static Game*        GetGame();
		void                Run();

	private:
		static Game*        mGame;
	};
}