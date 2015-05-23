#include <stdlib.h>
#include <stdio.h>
#include "SDLS.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define NOIR 0

struct pion {
	int x, y;
	int color;
} typedef pion;


int draw_pion(SDL_Renderer *renderer, pion *p);
pion *create_pion(int x, int y, int color);
void *move_pion(SDL_Renderer *renderer, pion *p, int nx, int ny, int size);
int *init_game(SDL_Renderer *renderer);