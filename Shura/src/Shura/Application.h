#pragma once

#include "Core.h"

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


