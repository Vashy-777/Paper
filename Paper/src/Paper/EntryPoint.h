#pragma once


#ifdef P_PLATFORM_WINDOWS

extern Paper::Application* Paper::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Paper::CreateApplication();
	app->Run();
	delete app;
}

#endif