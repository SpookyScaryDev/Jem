#include <Jem.h>

using namespace Jem;

class TestComponent : public Component {
public:
	TestComponent(int number) :
		mNumber(number)
	{
		JEM_MESSAGE("Creating TestComponent");
	}

	~TestComponent() {
		JEM_MESSAGE("Destroying TestComponent");
	}

	void Print() {
		JEM_MESSAGE("Printing TestComponent");
		JEM_MESSAGE(mNumber);
	}

private:
	int mNumber;
};

class TestComponent2 : public Component {
public:
	TestComponent2(int number) :
		mNumber(number)
	{
		JEM_MESSAGE("Creating TestComponent2");
	}

	~TestComponent2() {
		JEM_MESSAGE("Destroying TestComponent2");
	}

	void Print() {
		JEM_MESSAGE("Printing TestComponent2");
		JEM_MESSAGE(mNumber);
	}

private:
	int mNumber;
};

class TestSystem : public System {
public:
	using System::System;

	~TestSystem() {
		JEM_MESSAGE("Destroying TestSystem");
	}

	void Update() override {
		JEM_MESSAGE("Updating TestSystem");

		for (TestComponent* t : ComponentIterator<TestComponent>(mAdmin))
			t->Print();

		for (TestComponent2* t : ComponentIterator<TestComponent2>(mAdmin))
			t->Print();
	}
};


class Sandbox : public Game {
public:
	Sandbox() {
		// Test ECS.
		printf("Create EntiyAdmin\n");
		EntityAdmin mAdmin;

		printf("Create Entity\n");
		mEntity = mAdmin.CreateEntity("TestEntity");
		printf("Create System (TestSystem)\n");
		mSystem = mAdmin.CreateSystem<TestSystem>();

		printf("Add TestComponent(1) and TestComonent2(2) to Entity\n");
		mEntity->Add<TestComponent>(1);
		mEntity->Add<TestComponent2>(2);

		printf("Create Entity2\n");
		mEntity2 = mAdmin.CreateEntity("TestEntity2");

		printf("Add TestComponent(3) and TestComonent2(4) to Entity2\n");
		mEntity2->Add<TestComponent>(3);
		mEntity2->Add<TestComponent2>(4);

		printf("Update EntityAdmin\n");
		mAdmin.Update();

		printf("Destroy TestEntiy2\n");
		mAdmin.DestroyEntity("TestEntity2");

		printf("Update EntityAdmin\n");
		mAdmin.Update();

		printf("Destroy TestSystem\n");
		mAdmin.RemoveSystem<TestSystem>();

		printf("Update EntityAdmin\n");
		mAdmin.Update();
	}

	void Update(double deltaTime) {
		/*if (Input::IsKeyPressed(JEM_KEY_SPACE)) {
			JEM_CORE_WARNING("Space Key Pressed");

			r = (rand() % 255) + 1;
			g = (rand() % 255) + 1;
			b = (rand() % 255) + 1;
		}
		Renderer::SetClearColour(r, g, b);*/

		static int i = 0;
		static double range = 500;

		JEM_MESSAGE(deltaTime);

		if (Input::IsKeyPressed(JEM_KEY_SPACE)) {
			JEM_CORE_WARNING("Space Key Pressed");
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
	}

private:
	EntityAdmin    mAdmin;
	Entity*  mEntity;
	Entity*  mEntity2;
	System*  mSystem;
};

namespace Jem {
	Game* CreateGame() {
		return new Sandbox();
	}
}