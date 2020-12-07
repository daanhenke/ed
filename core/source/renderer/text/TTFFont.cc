#include "renderer/text/TTFFont.hh"
#include <locale>
#include <codecvt>

namespace ed::renderer::text
{
    TTFFont::TTFFont(std::wstring path, int size)
    {
        std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> string_converter;
        auto mbstr = string_converter.to_bytes(path);

        m_sdl_font = TTF_OpenFont(mbstr.c_str(), size);
    }

    TTFFont::~TTFFont()
    {
        TTF_CloseFont(m_sdl_font);
    }
}