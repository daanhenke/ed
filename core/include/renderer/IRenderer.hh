#pragma once
#include "public/types.h"

namespace ed::renderer
{
    class IRenderer
    {
    public:
        virtual status_t Initialize() = 0;
        virtual void Loop() = 0;
        virtual status_t Destroy() = 0;
    };
}