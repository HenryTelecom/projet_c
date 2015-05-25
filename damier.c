#include "damier.h"
#include "pion.h"

SDL_Rect *draw_damier(SDL_Window *window, SDL_Renderer *renderer)
{
	SDL_Rect *rectangles;
	int ln, cn,
		pion_size = get_pion_size();


	rectangles = malloc(sizeof(SDL_Rect)*10);

	for (cn = 0; cn <= 9; cn+=2) {
		for (ln = 0; ln<=9 ; ln++) {
			rectangles[ln].x = (cn+(ln+1)%2) *pion_size;
			rectangles[ln].y = ln *pion_size;
			rectangles[ln].w = pion_size;
			rectangles[ln].h = pion_size;

			SDL_SetRenderDrawColor(renderer, 102, 51, 0, 255);
			SDL_RenderFillRect(renderer, &rectangles[ln]);
		}
	}

	return rectangles;
}
