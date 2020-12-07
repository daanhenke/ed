#include <iostream>
#include "Application.hh"

int main(int argc, const char **argv)
{
    std::cout << "Hello" << std::endl;

    ed::Instance = new ed::Application();
    ed::Instance->InitializeRenderer();
    std::cout << "Renderer: " << std::hex << ed::Instance->m_renderer << std::endl;

    ed::Instance->Run();
    ed::Instance->m_renderer->Destroy();

    return 0;
}