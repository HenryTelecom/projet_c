#include "window.h"


int getscreenheight() {
    int i;
    int screen_height;


    SDL_DisplayMode current;

    SDL_Init(SDL_INIT_VIDEO);


    for(i = 0; i < SDL_GetNumVideoDisplays(); ++i){

        SDL_GetCurrentDisplayMode(i, &current);   /*current.h c'est la "hauteur" de l'écran !*/

    }
    screen_height = (current.h) - (((current.h)%100) + (current.h)/10);

    return screen_height;
}





SDL_Renderer *create_window(SDL_Window* window)
{
    SDL_Renderer* renderer = NULL;

    
    window = SDL_CreateWindow
    (
        "Jeu de dames", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        getscreenheight(),
        getscreenheight(),
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
