#include "ppch.h"
#include "Application.h"

#include "Paper\Events\ApplicationEvent.h"
#include "Paper\Log.h"

namespace Paper 
{

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			P_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			P_TRACE(e);
		}
		while (true);
	}

}