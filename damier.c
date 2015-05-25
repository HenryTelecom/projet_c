#include "damier.h"
#include "pion.h"

SDL_Rect *create_damier(SDL_Window *window, SDL_Renderer *renderer)
{	
	SDL_Rect *rectangles;
	int ln, cn;
	int gps = get_pion_size();


    /* Create a rectangle at pos ( (cn+(ln+1)%2) * 100, ln * 100 ) that's 100 pixels wide and 100 pixels high.*/
	rectangles = malloc(sizeof(SDL_Rect)*10);

	for (cn = 0; cn <= 9; cn+=2)
	{
		for (ln = 0; ln<=9 ; ln++)
		{
			rectangles[ln].x = (cn+(ln+1)%2) *gps;
			rectangles[ln].y = ln *gps;
			rectangles[ln].w = gps;
			rectangles[ln].h = gps;
    		
			SDL_SetRenderDrawColor( renderer, 102, 51, 0, 255 );
			/* Render rectangle*/
			SDL_RenderFillRect(renderer, &rectangles[ln]);
		}
	}

	/* Render the rectangle to the screen*/
	SDL_RenderPresent(renderer);

	return rectangles;
}
