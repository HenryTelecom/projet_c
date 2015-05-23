#include <stdio.h>

#include <SDL2/SDL.h>

#include "window.h"
#include "damier.h"

int getscreenheight();

int main()
{
	int quit = 0;
    SDL_Event e;


    SDL_Window *window = NULL;

    int window_h = getscreenheight();

    SDL_Renderer *renderer = create_window(window, window_h);

    damier(window, renderer, window_h/10 - 3);


    while( !quit ) {
    	/*Handle events on queue*/
        while( SDL_PollEvent( &e ) != 0 )
        {
            /*User requests quit*/
            if( e.type == SDL_QUIT )
            {
                quit = 1;
            }
        }
    }

    return 0;
}


int getscreenheight() {
    int i;

    SDL_DisplayMode current;

    SDL_Init(SDL_INIT_VIDEO);


    for(i = 0; i < SDL_GetNumVideoDisplays(); ++i){

        SDL_GetCurrentDisplayMode(i, &current);   /*current.h c'est la "hauteur" de l'écran !*/

    }

    return current.h;
}

