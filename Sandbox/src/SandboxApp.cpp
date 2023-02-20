#include <Shura.h>


class Sandbox : public Shura::Application {
public: 
	Sandbox() {}
	~Sandbox() {}

};
Shura::Application* Shura::CreateApplication() {
	return new Sandbox();
}