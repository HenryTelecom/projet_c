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


int Drawpion(SDL_Window *window, SDL_Renderer *renderer, pion *p);