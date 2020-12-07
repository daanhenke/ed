#pragma once
#include "renderer/IRenderer.hh"
#include <locale>
#include <codecvt>

namespace ed::renderer
{
    class TerminalRenderer : public IRenderer
    {
    public:
        std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> m_string_converter;

        status_t Initialize();
        void Loop();
        status_t Destroy();
        
        void RenderText(unsigned long cell_x, unsigned long cell_y, std::wstring string);
        void RenderCharacter(unsigned long cell_x, unsigned long cell_y, wchar_t character);
    };
}