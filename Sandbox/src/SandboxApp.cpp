#include <Paper.h>

class Sandbox : public Paper::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Paper::Application* Paper::CreateApplication()
{
	return new Sandbox();
}