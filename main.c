#include <stdio.h>

#include <SDL2/SDL.h>

#include "window.h"
#include "damier.h"
#include "pion.h"

int main()
{
	int quit = 0;
    SDL_Event e;

    SDL_Window *window = NULL;

    SDL_Renderer *renderer = create_window(window);

    pion p;

    p.x = 1;
    p.y = 0;
    p.color = 1;

    damier(window, renderer);
    Drawpion(window, renderer, &p);


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
