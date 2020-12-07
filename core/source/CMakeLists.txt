add_executable(ed)

find_package(SDL2 REQUIRED)
find_package(curses REQUIRED)

target_sources(ed
    PRIVATE
        main.cc
        Application.cc
        renderer/TerminalRenderer.cc
        renderer/GraphicalRenderer.cc
)
target_include_directories(ed PUBLIC ${CMAKE_SOURCE_DIR}/core/include)
target_link_libraries(ed SDL2 curses)