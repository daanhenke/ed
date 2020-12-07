add_executable(ed)

find_package(SDL2 REQUIRED)

set(CURSES_NEED_WIDE TRUE)
set(CURSES_NEED_NCURSES TRUE)
find_package(curses REQUIRED)

target_sources(ed
    PRIVATE
        main.cc
        Application.cc
        renderer/TerminalRenderer.cc
        renderer/GraphicalRenderer.cc
        renderer/text/FontManager.cc
)
target_include_directories(ed PUBLIC ${CMAKE_SOURCE_DIR}/core/include)
target_link_libraries(ed SDL2 SDL2_ttf curses)