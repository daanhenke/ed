#pragma once
#include "renderer/IRenderer.hh"
#include "renderer/text/FontManager.hh"
#include <SDL2/SDL.h>

namespace ed::renderer
{
    class GraphicalRenderer : public IRenderer
    {
    public:
        GraphicalRenderer();

        SDL_Window* m_sdl_window;
        SDL_Renderer* m_sdl_renderer;
        SDL_Event m_sdl_current_event;

        text::FontManager* m_font_manager;

        status_t Initialize();
        void Loop();
        status_t Destroy();
        
        void RenderText(unsigned long cell_x, unsigned long cell_y, std::wstring string);
        void RenderCharacter(unsigned long cell_x, unsigned long cell_y, wchar_t character);
    };
}