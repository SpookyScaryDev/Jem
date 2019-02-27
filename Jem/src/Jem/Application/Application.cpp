#include "Application.h"
#include <Jem/Log/Log.h>
#include <Jem/GameObject/GameObject.h>
#include <Jem/GameObject/Components/Component.h>
#include <Jem/GameObject/Components/Components.h>
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