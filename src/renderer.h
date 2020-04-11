
#ifndef RENDERER_H
#define RENDERER_H


#include <map>
#include "SDL.h"


class GameBlock;
class Shape;



/**
 * Class defining a renderer for the game.
 */
class renderer
{
public:
    
    renderer(std::size_t window_width, std::size_t window_height);
    ~renderer();

    void render(const GameBlock &gb, const Shape &shape_, int x, int y, uint score, uint level);

private:
    
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;

    std::size_t window_width;
    std::size_t window_height;

    
    void render_background(std::size_t cell_width, std::size_t cell_height);
    void render_gameblock(const GameBlock &gb, std::size_t cell_width, std::size_t cell_height);
    
    void render_shape(const Shape &shape_, int x, int y, std::size_t cell_width, std::size_t cell_height);
};


#endif  /* RENDERER_H */
