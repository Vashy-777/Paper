#pragma once

#include "Core.h"

#include "Window.h"
#include "Paper/LayerStack.h"
#include "Paper/Events/Event.h"
#include "Paper/Events/ApplicationEvent.h"


namespace Paper 
{
	class PAPER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}