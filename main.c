#include <stdio.h>

#include <SDL2/SDL.h>

#include "window.h"
#include "damier.h"
<<<<<<< HEAD
#include "pion.h"
=======

int getscreenheight();
>>>>>>> 7f730f829637f2267de1c91cbd80e95cba29d38d

int main()
{
	int quit = 0;
    SDL_Event e;


    SDL_Window *window = NULL;

    int window_h = getscreenheight();

    SDL_Renderer *renderer = create_window(window, window_h);

    damier(window, renderer, window_h/10 - 3);


<<<<<<< HEAD
    pion p;

    p.x = 1;
    p.y = 0;
    p.color = 1;

    damier(window, renderer);
    Drawpion(window, renderer, &p);

=======
    create_damier(window, renderer);
>>>>>>> 7f730f829637f2267de1c91cbd80e95cba29d38d

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

