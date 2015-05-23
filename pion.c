#include "pion.h"

int getscreenheight();

int draw_pion(SDL_Renderer *renderer, pion *p)
{
    int size_case = getscreenheight();
    	
	char *filename = p->color == NOIR ? "pionNoir2.bmp" : "pionBlanc2.bmp";
	size_case = (size_case - ((size_case%100) + size_case/10))/10;

	SDLS_affiche_image(filename, renderer, size_case * p->x, size_case * p->y, size_case, size_case);
	 

	return 0;
}

pion *create_pion(int x, int y, int color){

	pion *p = malloc(sizeof(pion));

	p->x = x;
    p->y = y;
    p->color = color;

    return p;
}

void *move_pion(SDL_Renderer *renderer, pion *p, int nx, int ny, int size){

	SDL_Rect emplacement_vide;

	emplacement_vide.x = (p->x)*size;
	emplacement_vide.y = (p->y)*size;
	emplacement_vide.w = size;
	emplacement_vide.h = size;

	SDL_SetRenderDrawColor( renderer, 102, 51, 0, 255 );
	SDL_RenderFillRect(renderer, &emplacement_vide);
	SDL_RenderPresent(renderer);

	p->x = nx;
	p->y = ny;
	draw_pion(renderer, &p[0]);



}

int *init_game(SDL_Renderer *renderer){

	int ln, cn;

	pion *p;

	for (cn = 0; cn <= 9; cn+=2)
	{
		for (ln = 0; ln<=3 ; ln ++)
		{
			p = create_pion(cn+(ln+1)%2,ln,0);
			draw_pion(renderer, p);
		}
	}

	for (cn = 0; cn <= 9; cn+=2)
	{
		for (ln = 6; ln<=9 ; ln ++)
		{
			p = create_pion(cn+(ln+1)%2,ln,1);
			draw_pion(renderer, p);
		}
	}
	return 0;

}