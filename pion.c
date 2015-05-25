#include "pion.h"


int get_pion_size() { return get_screen_height() / 10; }


int draw_pion(SDL_Renderer *renderer, pion *p)
{
	int pion_size = get_pion_size();

	char *filename = p->color == NOIR ? "pionNoir2.bmp" : "pionBlanc2.bmp";

	SDLS_affiche_image(	filename,
						renderer,
						pion_size * p->x,
						pion_size * p->y,
						pion_size,
						pion_size );

	return 0;
}

void draw_pions(SDL_Renderer *renderer, pion *boite_pions)
{
	int i;

	for (i = 0; i < 40; i++) {
		draw_pion(renderer, &boite_pions[i]);
	}
}

pion *create_pion(int x, int y, int color)
{

	pion *p = malloc(sizeof(pion));

	p->x = x;
    p->y = y;
    p->color = color;

    return p;
}


pion *init_game()
{

	int ln, cn;
	int cpt = 0;

	pion* boite_pions = malloc(sizeof(pion) * 40);

	for (ln = 0; ln < 4 ; ln++) {
		for (cn = 0; cn < 10; cn+=2) {
			boite_pions[cpt].x = cn + (ln + 1)%2;
			boite_pions[cpt].y = ln;
			boite_pions[cpt].color = 0;
			boite_pions[cpt].dame  = 0;

			cpt ++;
		}
	}

	for (ln = 6; ln < 10; ln++) {
		for (cn = 0; cn < 10; cn+=2) {
			boite_pions[cpt].x = cn+(ln+1)%2;
			boite_pions[cpt].y = ln;
			boite_pions[cpt].color = 1;
			boite_pions[cpt].dame = 0;

			cpt ++;
		}
	}

	return boite_pions;
}


pion *pion_at_coord(pion *boite_pions, int x, int y)
{
	int i;

	pion *p = malloc(sizeof(pion));
	p->x = x;
	p->y = y;

	for (i = 0; i < 40; i++) {
		if (pions_are_same(p, &boite_pions[i])) return &boite_pions[i];
	}

	return NULL;
}

int pions_are_same(pion *p1, pion *p2)
{
	return p1->x == p2->x && p1->y == p2->y;
}

int pion_can_move_at(pion *p, int x, int y)
{
	if ((p->x - x == 1 || p->x - x == -1) && (p->y - y == 1 || p->y - y == -1)) return (x + y) % 2 == 1;

	return 0;
}
