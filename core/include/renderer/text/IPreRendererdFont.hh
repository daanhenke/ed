#pragma once
#include <string>
#include <SDL2/SDL.h>

namespace ed::renderer::text
{
    class IPreRenderedFont
    {
    public:
        SDL_Texture* GetFontTexture();
        SDL_Rect GetCharRect(wchar_t character);
    };
}