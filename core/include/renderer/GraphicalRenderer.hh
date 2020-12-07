#pragma once
#include "renderer/IRenderer.hh"
#include <SDL2/SDL.h>

namespace ed::renderer
{
    class GraphicalRenderer : public IRenderer
    {
    public:
        SDL_Window* m_sdl_window;
        SDL_Renderer* m_sdl_renderer;
        SDL_Event m_sdl_current_event;

        status_t Initialize();
        void Loop();
        status_t Destroy();
    };
}