#pragma once
#include "public/types.h"
#include <string>

namespace ed::renderer
{
    class IRenderer
    {
    public:
        unsigned long m_cell_width;
        unsigned long m_cell_height;

        virtual status_t Initialize() = 0;
        virtual void Loop() = 0;
        virtual status_t Destroy() = 0;
        
        virtual void RenderText(unsigned long cell_x, unsigned long cell_y, std::wstring string) = 0;
        virtual void RenderCharacter(unsigned long cell_x, unsigned long cell_y, wchar_t character) = 0;
    };
}