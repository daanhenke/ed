#include "renderer/TerminalRenderer.hh"
#include "Application.hh"
#include <ncurses.h>

namespace ed::renderer
{
    status_t TerminalRenderer::Initialize()
    {
        // Initialize ncurses
        initscr();
        clear();
        raw();
        noecho();
        keypad(stdscr, TRUE);

        // Get the screen size
        getmaxyx(stdscr, m_cell_height, m_cell_width);

        return 0;
    }

    // FIXME: Split this function up into RenderStart and RenderEnd for TerminalRenderer & GraphicalRenderer
    void TerminalRenderer::Loop()
    {
        // FIXME: getch currently halts the program until the user has pressed a key
        int character = getch();

        switch (character)
        {
        case 'q':
            ed::Instance->Halt();
            break;
        
        default:
            break;
        }

        RenderText(0, 0, L"Yeet!");
        for (int i = 0; i < 10; i++)
        {
            RenderCharacter(i, 1, L'=');
        }

        refresh();
    }

    status_t TerminalRenderer::Destroy()
    {
        endwin();
        return 0;
    }
    
    void TerminalRenderer::RenderText(unsigned long cell_x, unsigned long cell_y, std::wstring string)
    {
        auto mbstring = m_string_converter.to_bytes(string);
        mvaddstr(cell_y, cell_x, mbstring.c_str());
    }
    
    void TerminalRenderer::RenderCharacter(unsigned long cell_x, unsigned long cell_y, wchar_t character)
    {
        std::string mbstring(MB_CUR_MAX, '\0');
        std::wctomb(&mbstring[0], character);
        mvaddstr(cell_y, cell_x, mbstring.c_str());
    }
}