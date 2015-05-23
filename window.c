#include "window.h"

SDL_Renderer *create_window(SDL_Window* window, int height)
{
    SDL_Renderer* renderer = NULL;

    
    window = SDL_CreateWindow
    (
        "Jeu de dames", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        height,
        height,
        SDL_WINDOW_SHOWN
    );

    
    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);

    
    /* Set render color to white ( background will be rendered in this color )*/
    SDL_SetRenderDrawColor(renderer, 255, 204, 153, 255);
    /* Clear window*/
    SDL_RenderClear( renderer );

    return renderer;
}

void closeWindow(SDL_Window* window)
{
    SDL_DestroyWindow(window);
}
