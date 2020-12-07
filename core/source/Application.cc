#include "Application.hh"
#include "renderer/TerminalRenderer.hh"
#include "renderer/GraphicalRenderer.hh"

namespace ed
{
    Application::Application()
    {
        m_running = false;
    }

    status_t Application::InitializeRenderer()
    {
        m_renderer = new renderer::GraphicalRenderer();
        m_renderer->Initialize();

        return 0;
    }

    void Application::Run()
    {
        m_running = true;

        while (m_running)
        {
            m_renderer->Loop();
        }
    }

    Application* Instance;
}