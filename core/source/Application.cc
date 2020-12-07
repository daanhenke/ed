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
        // FIXME: Choose a renderer based on CLI options
        m_renderer = new renderer::TerminalRenderer();
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

    void Application::Halt()
    {
        m_running = false;
    }

    Application* Instance;
}