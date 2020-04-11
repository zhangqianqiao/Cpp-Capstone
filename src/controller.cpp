
#include "SDL.h"

#include "controller.h"


input controller::getInput() const
{
    SDL_Event e;
    input iEvent = input::None;

    if (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            iEvent = input::Quit;
        }
        else if (e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym)
            {
            case SDLK_UP:
            case SDLK_x:
                iEvent = input::RotateLeft;
                break;
            case SDLK_z:
                iEvent = input::RotateRight;
                break;
            
            case SDLK_DOWN:
                iEvent = input::Down;
                break;

            case SDLK_RIGHT:
                iEvent = input::Right;
                break;

            case SDLK_LEFT:
                iEvent = input::Left;
                break;

            case SDLK_ESCAPE:
                iEvent = input::Quit;
                break;

            case SDLK_SPACE:
                iEvent = input::Drop;
                break;

            default:
                break;
            }
        }
    }

    return iEvent;
}