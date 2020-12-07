#pragma once
#include "renderer/text/IPreRendererdFont.hh"
#include <SDL2/SDL_ttf.h>

namespace ed::renderer::text
{
    class TTFFont : public IPreRenderedFont
    {
    public:
        TTFFont(std::wstring path, int size);
        ~TTFFont();

        TTF_Font* m_sdl_font;
    };
}