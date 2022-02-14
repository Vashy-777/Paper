#pragma once


#ifdef P_PLATFORM_WINDOWS

extern Paper::Application* Paper::CreateApplication();

int main(int argc, char** argv)
{
	Paper::Log::Init();
	P_CORE_WARN("Initialized Log!");
	int a = 5;
	P_CORE_INFO("Hello! var={0}", a);

	auto app = Paper::CreateApplication();
	app->Run();
	delete app;
}

#endif