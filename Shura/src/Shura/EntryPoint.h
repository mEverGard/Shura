#pragma once

#ifdef SH_PLATFORM_WINDOWS
extern Shura::Application* Shura::CreateApplication();

int main(int argc, char** argv) {
	Shura::Log::Init();
	SH_CORE_WARN("Initialized Log!");
	SH_INFO("HEY");
	auto app = Shura::CreateApplication();
	app->Run();
	delete app;
}
#endif