#include <stdlib.h>
#include <stdio.h>
#include "SDLS.h"
#include <SDL2/SDL.h>
#include "window.h"
#define NOIR 0
#define DAME 0

struct pion {
	int x, y;
	int color; /*0 si noir, 1 si blanc*/
	int size_pion;
	int dame; /*1 si dame, 0 sinon*/
} typedef pion;


int get_pion_size();
int draw_pion(SDL_Renderer *renderer, pion *p);
pion *create_pion(int x, int y, int color);
pion *init_game();
pion *pion_at_coord(pion *boite_pions, int x, int y);
int pions_are_same(pion *p1, pion *p2);
void draw_pions(SDL_Renderer *renderer, pion *boite_pions);
int pion_can_move_at(pion *p, int x, int y);
