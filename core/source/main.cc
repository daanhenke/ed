#include <iostream>
#include "Application.hh"

int main(int argc, const char **argv)
{
    std::cout << "Hello" << std::endl;

    ed::Instance = new ed::Application();
    // FIXME: Implement Initialize method on Application
    ed::Instance->InitializeRenderer();
    std::cout << "Renderer: " << std::hex << ed::Instance->m_renderer << std::endl;

    ed::Instance->Run();

    std::cout << "Window size: " << std::dec << ed::Instance->m_renderer->m_cell_width << ", " << ed::Instance->m_renderer->m_cell_height << std::endl;

    // FIXME: Implement Destroy method on Application
    ed::Instance->m_renderer->Destroy();

    return 0;
}