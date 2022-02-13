#pragma once

#include "Core.h"

namespace Paper 
{
	class PAPER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}