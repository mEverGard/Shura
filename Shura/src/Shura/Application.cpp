#include "hzpch.h"
#include "Application.h"
#include "Shura/Events/ApplicationEvent.h"
#include "Shura/Log.h"

namespace Shura {
	Application::Application()
	{
	}
	Application::~Application() {
	}
	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			SH_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SH_TRACE(e);
		}
		while(true){}
	}
}