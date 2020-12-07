#include "renderer/GraphicalRenderer.hh"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Application.hh"

namespace ed::renderer
{
    GraphicalRenderer::GraphicalRenderer()
    {
        m_font_manager = new text::FontManager();
    }

    status_t GraphicalRenderer::Initialize()
    {
        SDL_Init(SDL_INIT_VIDEO);
        TTF_Init();

        m_sdl_window = SDL_CreateWindow("ed", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
        m_sdl_renderer = SDL_CreateRenderer(m_sdl_window, -1, 0);

        m_font_manager->RegisterFont(L"arial", L"Arial.ttf");

        return 0;
    }

    status_t GraphicalRenderer::Destroy()
    {
        SDL_DestroyRenderer(m_sdl_renderer);
        SDL_DestroyWindow(m_sdl_window);

        TTF_Quit();
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
                    ed::Instance->Halt();
                    break;
            }
        }
        
        SDL_RenderClear(m_sdl_renderer);
        RenderText(0, 0, L"Yeet!");
        SDL_RenderPresent(m_sdl_renderer);
    }

    void GraphicalRenderer::RenderText(unsigned long cell_x, unsigned long cell_y, std::wstring string)
    {
    }
    
    void GraphicalRenderer::RenderCharacter(unsigned long cell_x, unsigned long cell_y, wchar_t character)
    {
        
    }
}