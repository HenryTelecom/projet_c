#include <stdlib.h>
#include <stdio.h>
#include "SDLS.h"
#include <SDL2/SDL.h>
#include "window.h"
#define NOIR 0
#define BLANC 1
#define DAME 1

struct pion {
	int x, y;
	int color; /*0 si noir, 1 si blanc*/
	int size_pion;
	int dame; /*1 si dame, 0 sinon*/
} typedef pion;

SDL_Texture* load_texture_pion(char * filename, SDL_Renderer *ren);
void affiche_pion(char * fname,SDL_Renderer * ren, int x, int y, int w, int h);
void affiche_pion2(SDL_Renderer * ren, pion *p, SDL_Texture * tex);
int get_pion_size();
int draw_pion(SDL_Renderer *renderer, pion *p, SDL_Texture * tex_n, SDL_Texture * tex_b, SDL_Texture * tex_dn, SDL_Texture * tex_db);
pion *create_pion(int x, int y, int color);
int *move_pion(SDL_Renderer *renderer, int num_pion, pion *boite_pions, int nx, int ny);
pion *init_game(SDL_Renderer *renderer);
int *deplace_p(pion *boite_pions);
