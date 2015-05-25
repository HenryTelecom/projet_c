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
int *move_pion(SDL_Renderer *renderer, int num_pion, pion *boite_pions, int nx, int ny);
pion *init_game(SDL_Renderer *renderer);
int *deplace_p(pion *boite_pions);
