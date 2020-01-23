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