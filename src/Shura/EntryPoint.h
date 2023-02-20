#pragma once

#ifdef SH_PLATFORM_WINDOWS
extern Shura::Application* Shura::CreateApplication();

int main(int argc, char** argv) {
	printf("Shura Engine startin\n");
	auto app = Shura::CreateApplication();
	app->Run();
	delete app;
}
#endif