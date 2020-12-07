#pragma once
#include "public/types.h"
#include "renderer/IRenderer.hh"

namespace ed
{
    class Application
    {
    public:
        Application();

        bool m_running;
        renderer::IRenderer* m_renderer;

        status_t InitializeRenderer();
        void Run();
    };

    extern Application* Instance;
}