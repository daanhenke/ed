#pragma once
#include "renderer/IRenderer.hh"

namespace ed::renderer
{
    class TerminalRenderer : public IRenderer
    {
    public:
        status_t Initialize();
    };
}