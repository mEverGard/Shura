#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Shura {
	class SHURA_API Application
	{
	public:
		Application();
		virtual ~Application(); 
		void Run();
	};
	// to be defined in client
	Application* CreateApplication();
}


