#include <Paper.h>

class ExampleLayer : public Paper::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		P_INFO("ExampleLayer::Update");
	}
	void OnEvent(Paper::Event& event) override
	{
		P_TRACE("{0}", event);
	}
};

class Sandbox : public Paper::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Paper::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Paper::Application* Paper::CreateApplication()
{
	return new Sandbox();
}