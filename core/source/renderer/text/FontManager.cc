#include "renderer/text/FontManager.hh"
#include <filesystem>

// FIXME: Get this into a seperate header to avoid duplication and make it easier to migrate to a polyfill if wanted
namespace fs = std::filesystem;

namespace ed::renderer::text
{
    FontManager::FontManager()
    {
        m_default_font = nullptr;
    }

    status_t FontManager::RegisterFont(std::wstring name, std::wstring path)
    {
        
        return 0;
    }
}