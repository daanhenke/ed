#pragma once
#include <map>
#include <string>
#include "public/types.h"
#include "renderer/text/IPreRendererdFont.hh"

namespace ed::renderer::text
{
    class FontManager
    {
    public:
        FontManager();

        std::map<std::string, IPreRenderedFont*> m_font_map;
        IPreRenderedFont* m_default_font;
        
        status_t RegisterFont(std::wstring name, std::wstring path);
    };
}