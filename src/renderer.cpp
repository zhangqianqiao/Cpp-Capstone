
#include <iostream>
#include <map>

#include "SDL.h"

#include "gameblock.h"
#include "renderer.h"
#include "shape.h"


/*const std::map<cell_state, tetromino_color> renderer::colormap = {
    { cell_state::filled_with_i, i_tetromino().color(), },
    { cell_state::filled_with_j, j_tetromino().color(), },
    { cell_state::filled_with_l, l_tetromino().color(), },
    { cell_state::filled_with_o, o_tetromino().color(), },
    { cell_state::filled_with_s, s_tetromino().color(), },
    { cell_state::filled_with_t, t_tetromino().color(), },
    { cell_state::filled_with_z, z_tetromino().color(), },
};*/


renderer::renderer(std::size_t window_width, std::size_t window_height)
    : window_width(window_width),
      window_height(window_height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << '\n';
    }

    sdl_window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, window_width,
                                  window_height, SDL_WINDOW_SHOWN);
    if (sdl_window == nullptr)
    {
        std::cerr << "Window could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << '\n';
    }

    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (sdl_renderer == nullptr)
    {
        std::cerr << "Hardware Accelearted Renderer could not be created.\n";
        std::cerr << "Using Software renderer.\n";
        sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_SOFTWARE);
        if (sdl_renderer == nullptr)
        {
            std::cerr << "Software Renderer could not be created.\n";
            std::cerr << "SDL_Error: " << SDL_GetError() << '\n';
        }
    }
}


renderer::~renderer()
{
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}


void renderer::render(const GameBlock &gb, const Shape &shape_, int x, int y, uint score, uint level)
{
    const std::size_t cell_width = window_width / gb.getColumns();
    const std::size_t cell_height = window_height / gb.getRows();

    render_background(cell_width, cell_height);
    render_shape(shape_, x, y, cell_width, cell_height);
    render_gameblock(gb, cell_width, cell_height);

    // Update window title with the current score
    const std::string title { "Tetris - Score: " + std::to_string(score) + ", Level: " + std::to_string(level) };
    SDL_SetWindowTitle(sdl_window, title.c_str());

    // Update screen
    SDL_RenderPresent(sdl_renderer);
}


void renderer::render_background(std::size_t cell_width, std::size_t cell_height)
{
    uint8_t r = 0x0, g = 0x0, b = 0x0;

    // Clear screen with "empty" color.
    //get_color_coordinates(cell_state::empty, r, g, b);
    SDL_SetRenderDrawColor(sdl_renderer, r, g, b, 0xFF);
    SDL_RenderClear(sdl_renderer);

    // Draw some grid lines to help the player.
    SDL_SetRenderDrawColor(sdl_renderer, 0x4E, 0x4E, 0x4E, 0xFF);
    for (std::size_t x = cell_width; x < window_width; x += cell_width)
    {
        SDL_RenderDrawLine(sdl_renderer, x, 0, x, window_height);
    }
    for (std::size_t y = cell_height; y < window_height; y += cell_height)
    {
        SDL_RenderDrawLine(sdl_renderer, 0, y, window_width, y);
    }
}


void renderer::render_gameblock(const GameBlock &gb, std::size_t cell_width, std::size_t cell_height)
{
    //uint8_t r = 0x0, g = 0x0, b = 0x0;

    SDL_Rect block;
    block.w = cell_width;
    block.h = cell_height;

    const auto cells = gb.getWell();
    for (std::size_t i = 0; i < cells.size(); ++i)
    {
        if (cells[i] != BlockState::NoBlock)
        {
            const std::size_t x_c = i % gb.getColumns();
            const std::size_t y_c = i / gb.getColumns();
            block.x = x_c * block.w;
            block.y = y_c * block.h;
            //get_color_coordinates(cells[i], r, g, b);
            SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
            SDL_RenderFillRect(sdl_renderer, &block);
        }
    }
}


void renderer::render_shape(const Shape &shape_, int x, int y, std::size_t cell_width, std::size_t cell_height)
{
    //uint8_t r = 0x0, g = 0x0, b = 0x0;

    SDL_Rect block;
    block.w = cell_width;
    block.h = cell_height;

    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
    const std::vector<int> tetrions = shape_.boxVector();
    for (std::size_t i = 0; i < tetrions.size(); ++i)
    {
        if (tetrions[i])
        {
            const std::size_t x_t = i % shape_.getBoxSize();
            const std::size_t y_t = i / shape_.getBoxSize();
            block.x = (x + x_t) * block.w;
            block.y = (y + y_t) * block.h;
            SDL_RenderFillRect(sdl_renderer, &block);
        }
    }
}
