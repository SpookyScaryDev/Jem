#include "Application/Application.h"
#include <Log/Log.h>
#include <GameObject/GameObject.h>
#include <GameObject/Components/Component.h>
#include <GameObject/Components/Components.h>
// TODO: pch
#include <iostream>

namespace Jem {

	Application* Application::mApplication = nullptr;

	Application::Application() :
		mComponents()
	{
		if (mApplication != nullptr) {
			JEM_CORE_ERROR("Application already exists. You can only create 1 Application");
		}

		mApplication = this;
	}
	
	Application::~Application() {}

	Application* Application::GetApplication(){
		return mApplication;
	}

	void Application::Run() {
		JEM_CORE_MESSAGE("Running Application");

		std::cin.get();
	}

}