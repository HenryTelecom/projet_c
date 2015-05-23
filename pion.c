#include "pion.h"


int Drawpion(SDL_Window *window, SDL_Renderer *renderer, pion *p)

{
	char *filename = p->color == NOIR ? "pionNoir2.bmp" : "pionBlanc2.bmp";

	SDLS_affiche_image(filename, renderer, 100 * p->x, 100 * p->y, 100, 100);
	 
	return 0;
}

/*int InitGame(){
	pion *pions;

	pions = malloc(sizeof(pion)*40);
}*/