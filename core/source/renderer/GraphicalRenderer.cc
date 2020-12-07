#include "renderer/GraphicalRenderer.hh"
#include <SDL2/SDL.h>
#include <iostream>
#include "Application.hh"

namespace ed::renderer
{
    status_t GraphicalRenderer::Initialize()
    {
        std::cout << "Hello from renderer" << std::endl;
        SDL_Init(SDL_INIT_VIDEO);

        m_sdl_window = SDL_CreateWindow("hello", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
        m_sdl_renderer = SDL_CreateRenderer(m_sdl_window, -1, 0);

        return 0;
    }

    status_t GraphicalRenderer::Destroy()
    {
        SDL_DestroyRenderer(m_sdl_renderer);
        SDL_DestroyWindow(m_sdl_window);

        SDL_Quit();

        return 0;
    }

    void GraphicalRenderer::Loop()
    {
        while (SDL_PollEvent(&m_sdl_current_event))
        {
            switch (m_sdl_current_event.type)
            {
                case SDL_QUIT:
                    ed::Instance->m_running = false;
                    break;
            }
        }
        
        SDL_RenderClear(m_sdl_renderer);
        SDL_RenderPresent(m_sdl_renderer);
    }
}