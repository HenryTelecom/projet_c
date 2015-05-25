#include "window.h"


int get_screen_height() {
    int i;

    SDL_DisplayMode current;

    SDL_Init(SDL_INIT_VIDEO);


    for(i = 0; i < SDL_GetNumVideoDisplays(); ++i){
        SDL_GetCurrentDisplayMode(i, &current);   /*current.h c'est la "hauteur" de l'écran !*/
    }

    /*WTF ?? --> screen_height = (current.h) - (((current.h)%100) + (current.h)/10); Ça fait une fenetre trop grande non ?*/

    return current.h/2; /* Provisoire */
}


SDL_Renderer *create_window(SDL_Window* window)
{
    SDL_Renderer* renderer = NULL;

    window = SDL_CreateWindow
    (
        "Jeu de dames", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        get_screen_height(),
        get_screen_height(),
        SDL_WINDOW_SHOWN
    );


    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 255, 204, 153, 255);
    SDL_RenderClear( renderer );

    return renderer;
}
