#include "pion.h"

SDL_Texture* load_texture_pion(char * filename, SDL_Renderer *ren){
        SDL_Texture *texture = 0;
        SDL_Surface *loadedImage = 0;
        loadedImage = SDL_LoadBMP(filename);
        if (!loadedImage)
          {
          fprintf(stderr,"Erreur chargement image : %s\n",SDL_GetError());
          return 0;
          }
 
        texture = SDL_CreateTextureFromSurface(ren, loadedImage);
        SDL_FreeSurface(loadedImage);
        if (texture == 0)
          {
          fprintf(stderr,"Erreur creation texture : %s\n",SDL_GetError());
          return 0;
          }
        return texture;
}

/*void affiche_pion(char * fname,SDL_Renderer * ren, int x, int y, int w, int h) 
{
  SDL_Texture * tex = 0;
  SDL_Rect dst;
 
  tex = load_texture_pion(fname,ren);
  if (tex == 0) return;
 

  SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
 
  
  dst.x = x; 
  dst.y = y; 
  dst.w = w; 
  dst.h = h;

 

  SDL_RenderCopy(ren, tex, NULL, &dst);
  SDL_RenderPresent(ren);
}*/

void affiche_pion2(SDL_Renderer * ren, pion *p, SDL_Texture * tex) 
{

  SDL_Rect dst;

  if (tex == 0) return;
 

  SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
 
  
  dst.x = get_pion_size() * p->x; 
  dst.y = get_pion_size() * p->y; 
  dst.w = get_pion_size(); 
  dst.h = get_pion_size();

  /*SDL_DestroyTexture(tex);*/
 

  SDL_RenderCopy(ren, tex, NULL, &dst);
  SDL_RenderPresent(ren);
}


int get_pion_size(){
	int pion_size;
	pion_size = getscreenheight()/10;
	return pion_size;
}


int draw_pion(SDL_Renderer *renderer, pion *p, SDL_Texture * tex_n, SDL_Texture * tex_b, SDL_Texture * tex_dn, SDL_Texture * tex_db)
{
	/*char *filename = p->color == NOIR ? "pionNoir2.bmp" : "pionBlanc2.bmp";*/
	if(p->dame == DAME){
		if(p->color == NOIR){
			affiche_pion2(renderer, p, tex_dn);
		}
		else if(p->color == BLANC){
			affiche_pion2(renderer, p, tex_db);
		}
	}
	else if(p->color == NOIR){
		affiche_pion2(renderer, p, tex_n);
	}
	else if (p->color == BLANC){
		affiche_pion2(renderer, p, tex_b);
	}

	/*
	affiche_pion(filename, renderer, get_pion_size() * p->x, get_pion_size() * p->y, get_pion_size(), get_pion_size());
	*/

	return 0;
}

pion *create_pion(int x, int y, int color){

	pion *p = malloc(sizeof(pion));

	p->x = x;
    p->y = y;
    p->color = color;

    return p;
}

int *move_pion(SDL_Renderer *renderer, int num_pion, pion *boite_pions, int nx, int ny){

	SDL_Rect emplacement_vide;
	int i = 0;
	int j = 0;
	int k = 0;
	SDL_Texture * tex_n = load_texture_pion("pionNoir2.bmp", renderer);
	SDL_Texture * tex_b = load_texture_pion("pionBlanc2.bmp", renderer);
    SDL_Texture * tex_dn = load_texture_pion("dameNoir4.bmp", renderer);
    SDL_Texture * tex_db = load_texture_pion("dameBlanc4.bmp", renderer);



	SDL_SetRenderDrawColor( renderer, 102, 51, 0, 255 );

	if(boite_pions[num_pion].dame != DAME){

		for(i = 0; i<40; i++){
			if(boite_pions[i].x == nx && boite_pions[i].y == ny){
				printf("Déplacement interdit, l'emplacement (%d,%d) est indisponible car le pion %d y est déjà\n", nx, ny, i);
				return 0;
			}
		}

		if(nx == boite_pions[num_pion].x - 1 || nx == boite_pions[num_pion].x + 1){
			if(ny == boite_pions[num_pion].y - 1 && boite_pions[num_pion].color == 1){
				emplacement_vide.x = (boite_pions[num_pion].x)*get_pion_size();
				emplacement_vide.y = (boite_pions[num_pion].y)*get_pion_size();
				emplacement_vide.w = get_pion_size();
				emplacement_vide.h = get_pion_size();

				
				SDL_RenderFillRect(renderer, &emplacement_vide);
				SDL_RenderPresent(renderer);

				boite_pions[num_pion].x = nx;
				boite_pions[num_pion].y = ny;
				draw_pion(renderer, &boite_pions[num_pion], tex_n, tex_b, tex_dn, tex_db);
				printf("Déplacement d'une case effectué\n");
				if(boite_pions[num_pion].y == 0 && boite_pions[num_pion].color == BLANC){
					boite_pions[num_pion].dame = DAME;
					draw_pion(renderer, &boite_pions[num_pion], tex_n, tex_b, tex_dn, tex_db);
					printf("Votre pion blanc s'est transformé en dame\n");
				}
				else if(boite_pions[num_pion].y == 9 && boite_pions[num_pion].color == NOIR){
					boite_pions[num_pion].dame = DAME;
					draw_pion(renderer, &boite_pions[num_pion], tex_n, tex_b, tex_dn, tex_db);
					printf("Votre pion noir s'est transformé en dame\n");
				}
				return 0;
			}

			else if (ny == boite_pions[num_pion].y + 1 && boite_pions[num_pion].color == 0){
				emplacement_vide.x = (boite_pions[num_pion].x)*get_pion_size();
				emplacement_vide.y = (boite_pions[num_pion].y)*get_pion_size();
				emplacement_vide.w = get_pion_size();
				emplacement_vide.h = get_pion_size();

				
				SDL_RenderFillRect(renderer, &emplacement_vide);
				SDL_RenderPresent(renderer);

				boite_pions[num_pion].x = nx;
				boite_pions[num_pion].y = ny;

				printf("Déplacement d'une case effectué\n");
				if(boite_pions[num_pion].y == 0 && boite_pions[num_pion].color == BLANC){
					boite_pions[num_pion].dame = DAME;
					printf("Votre pion blanc s'est transformé en dame\n");
				}
				else if(boite_pions[num_pion].y == 9 && boite_pions[num_pion].color == NOIR){
					boite_pions[num_pion].dame = DAME;
					printf("Votre pion noir s'est transformé en dame\n");
				}
				draw_pion(renderer, &boite_pions[num_pion], tex_n, tex_b, tex_dn, tex_db);
				return 0;
			}
			printf("Il est interdit de reculer d'une case\n");
			return 0;
		}

		else if(nx == boite_pions[num_pion].x - 2 && ny == boite_pions[num_pion].y - 2){
				for(i = 0; i<40; i++){
					if(boite_pions[i].x == nx + 1 && boite_pions[i].y == ny + 1 && boite_pions[i].color != boite_pions[num_pion].color){
						emplacement_vide.x = (boite_pions[num_pion].x)*get_pion_size();
						emplacement_vide.y = (boite_pions[num_pion].y)*get_pion_size();
						emplacement_vide.w = get_pion_size();
						emplacement_vide.h = get_pion_size();

						
						SDL_RenderFillRect(renderer, &emplacement_vide);
						SDL_RenderPresent(renderer);

						emplacement_vide.x = (boite_pions[i].x)*get_pion_size();
						emplacement_vide.y = (boite_pions[i].y)*get_pion_size();
						emplacement_vide.w = get_pion_size();
						emplacement_vide.h = get_pion_size();

						
						SDL_RenderFillRect(renderer, &emplacement_vide);
						SDL_RenderPresent(renderer);

						boite_pions[num_pion].x = nx;
						boite_pions[num_pion].y = ny;
						draw_pion(renderer, &boite_pions[num_pion], tex_n, tex_b, tex_dn, tex_db);
						if(boite_pions[num_pion].y == 0 && boite_pions[num_pion].color == BLANC){
							boite_pions[num_pion].dame = DAME;
							printf("Votre pion blanc s'est transformé en dame\n");
						}
						else if(boite_pions[num_pion].y == 9 && boite_pions[num_pion].color == NOIR){
							boite_pions[num_pion].dame = DAME;
							printf("Votre pion noir s'est transformé en dame\n");
						}
						/* place le pion mangé en (-1,-1) en dehors du plateau */
						boite_pions[i].x = -1;
						boite_pions[i].y = -1;
						printf("Vous avez mangé le pion adverse n°%d\n", i);
						return 0;
					}
				}
				printf("Déplacement de 2 cases interdit\n");
				return 0;
		}

		else if(nx == boite_pions[num_pion].x - 2 && ny == boite_pions[num_pion].y + 2){
				for(i = 0; i<40; i++){
					if(boite_pions[i].x == nx + 1 && boite_pions[i].y == ny - 1 && boite_pions[i].color != boite_pions[num_pion].color){
						emplacement_vide.x = (boite_pions[num_pion].x)*get_pion_size();
						emplacement_vide.y = (boite_pions[num_pion].y)*get_pion_size();
						emplacement_vide.w = get_pion_size();
						emplacement_vide.h = get_pion_size();

						
						SDL_RenderFillRect(renderer, &emplacement_vide);
						SDL_RenderPresent(renderer);

						emplacement_vide.x = (boite_pions[i].x)*get_pion_size();
						emplacement_vide.y = (boite_pions[i].y)*get_pion_size();
						emplacement_vide.w = get_pion_size();
						emplacement_vide.h = get_pion_size();

						
						SDL_RenderFillRect(renderer, &emplacement_vide);
						SDL_RenderPresent(renderer);

						boite_pions[num_pion].x = nx;
						boite_pions[num_pion].y = ny;
						draw_pion(renderer, &boite_pions[num_pion], tex_n, tex_b, tex_dn, tex_db);
						if(boite_pions[num_pion].y == 0 && boite_pions[num_pion].color == BLANC){
							boite_pions[num_pion].dame = DAME;
							printf("Votre pion blanc s'est transformé en dame\n");
						}
						else if(boite_pions[num_pion].y == 9 && boite_pions[num_pion].color == NOIR){
							boite_pions[num_pion].dame = DAME;
							printf("Votre pion noir s'est transformé en dame\n");
						}
						/* place le pion mangé en (-1,-1) en dehors du plateau */
						boite_pions[i].x = -1; 
						boite_pions[i].y = -1;
						printf("Vous avez mangé le pion adverse n°%d\n", i);
						return 0;
					}
				}
				printf("Déplacement de 2 cases interdit\n");
				return 0;

		}
		else if(nx == boite_pions[num_pion].x + 2 && ny == boite_pions[num_pion].y - 2){
				for(i = 0; i<40; i++){
					if(boite_pions[i].x == nx - 1 && boite_pions[i].y == ny + 1 && boite_pions[i].color != boite_pions[num_pion].color){
						emplacement_vide.x = (boite_pions[num_pion].x)*get_pion_size();
						emplacement_vide.y = (boite_pions[num_pion].y)*get_pion_size();
						emplacement_vide.w = get_pion_size();
						emplacement_vide.h = get_pion_size();

						
						SDL_RenderFillRect(renderer, &emplacement_vide);
						SDL_RenderPresent(renderer);

						emplacement_vide.x = (boite_pions[i].x)*get_pion_size();
						emplacement_vide.y = (boite_pions[i].y)*get_pion_size();
						emplacement_vide.w = get_pion_size();
						emplacement_vide.h = get_pion_size();

						
						SDL_RenderFillRect(renderer, &emplacement_vide);
						SDL_RenderPresent(renderer);

						boite_pions[num_pion].x = nx;
						boite_pions[num_pion].y = ny;
						if(boite_pions[num_pion].y == 0 && boite_pions[num_pion].color == BLANC){
							boite_pions[num_pion].dame = DAME;
							printf("Votre pion blanc s'est transformé en dame\n");
						}
						else if(boite_pions[num_pion].y == 9 && boite_pions[num_pion].color == NOIR){
							boite_pions[num_pion].dame = DAME;
							printf("Votre pion noir s'est transformé en dame\n");
						}
						draw_pion(renderer, &boite_pions[num_pion], tex_n, tex_b, tex_dn, tex_db);
						boite_pions[i].x = -1;
						boite_pions[i].y = -1;
						printf("Vous avez mangé le pion adverse n°%d\n", i);
						return 0;
					}
				}
				printf("Déplacement de 2 cases interdit\n");
				return 0;
		}
		else if(nx == boite_pions[num_pion].x + 2 && ny == boite_pions[num_pion].y + 2){
				for(i = 0; i<40; i++){
					if(boite_pions[i].x == nx - 1 && boite_pions[i].y == ny - 1 && boite_pions[i].color != boite_pions[num_pion].color){
						emplacement_vide.x = (boite_pions[num_pion].x)*get_pion_size();
						emplacement_vide.y = (boite_pions[num_pion].y)*get_pion_size();
						emplacement_vide.w = get_pion_size();
						emplacement_vide.h = get_pion_size();

						
						SDL_RenderFillRect(renderer, &emplacement_vide);
						SDL_RenderPresent(renderer);

						emplacement_vide.x = (boite_pions[i].x)*get_pion_size();
						emplacement_vide.y = (boite_pions[i].y)*get_pion_size();
						emplacement_vide.w = get_pion_size();
						emplacement_vide.h = get_pion_size();

						
						SDL_RenderFillRect(renderer, &emplacement_vide);
						SDL_RenderPresent(renderer);

						boite_pions[num_pion].x = nx;
						boite_pions[num_pion].y = ny;
						if(boite_pions[num_pion].y == 0 && boite_pions[num_pion].color == BLANC){
							boite_pions[num_pion].dame = DAME;
							printf("Votre pion blanc s'est transformé en dame\n");
						}
						else if(boite_pions[num_pion].y == 9 && boite_pions[num_pion].color == NOIR){
						boite_pions[num_pion].dame = DAME;
						printf("Votre pion noir s'est transformé en dame\n");
						}
						draw_pion(renderer, &boite_pions[num_pion], tex_n, tex_b, tex_dn, tex_db);
						boite_pions[i].x = -1;
						boite_pions[i].y = -1;
						printf("Vous avez mangé le pion adverse n°%d\n", i);
						return 0;
					}

				}
				printf("Déplacement de 2 cases interdit\n");
				return 0;
		}

		printf("Déplacement interdit\n");
		return 0;
	}

	else if (boite_pions[num_pion].dame == DAME){

		for(i = 0; i<40; i++){
			if(boite_pions[i].x == nx && boite_pions[i].y == ny){
				printf("Déplacement interdit, l'emplacement (%d,%d) est indisponible car le pion %d y est déjà\n", nx, ny, i);
				return 0;
			}
		}


		for(j=1; j<=9; j++)
		{
			if(nx == boite_pions[num_pion].x - j && ny == boite_pions[num_pion].y - j){
				for(i = 0; i<40; i++){
					if(boite_pions[i].x == nx + 1 && boite_pions[i].y == ny + 1 && boite_pions[i].color != boite_pions[num_pion].color){
						for(k=2; k<=j; k++){ 
							for(i = 0; i<40; i++){
								if(boite_pions[i].x == nx+k && boite_pions[i].y == ny+k){
									printf("Déplacement interdit, il y a plusieurs pions sur la diagonale\n");
									return 0;
								}
							}
							
						}

						emplacement_vide.x = (boite_pions[num_pion].x)*get_pion_size();
						emplacement_vide.y = (boite_pions[num_pion].y)*get_pion_size();
						emplacement_vide.w = get_pion_size();
						emplacement_vide.h = get_pion_size();

						
						SDL_RenderFillRect(renderer, &emplacement_vide);
						SDL_RenderPresent(renderer);

						emplacement_vide.x = (boite_pions[i].x)*get_pion_size();
						emplacement_vide.y = (boite_pions[i].y)*get_pion_size();
						emplacement_vide.w = get_pion_size();
						emplacement_vide.h = get_pion_size();

						
						SDL_RenderFillRect(renderer, &emplacement_vide);
						SDL_RenderPresent(renderer);

						boite_pions[num_pion].x = nx;
						boite_pions[num_pion].y = ny;
						draw_pion(renderer, &boite_pions[num_pion], tex_n, tex_b, tex_dn, tex_db);

						/* place le pion mangé en (-1,-1) en dehors du plateau */
						boite_pions[i].x = -1; 
						boite_pions[i].y = -1;
						printf("Vous avez mangé le pion adverse n°%d\n", i);
						return 0;
					}
				}

				emplacement_vide.x = (boite_pions[num_pion].x)*get_pion_size();
				emplacement_vide.y = (boite_pions[num_pion].y)*get_pion_size();
				emplacement_vide.w = get_pion_size();
				emplacement_vide.h = get_pion_size();
				SDL_RenderFillRect(renderer, &emplacement_vide);
				SDL_RenderPresent(renderer);
				boite_pions[num_pion].x = nx;
				boite_pions[num_pion].y = ny;
				draw_pion(renderer, &boite_pions[num_pion], tex_n, tex_b, tex_dn, tex_db);
				printf("Déplacement de %d cases\n", j);
				return 0;


			}

			if(nx == boite_pions[num_pion].x - j && ny == boite_pions[num_pion].y + j){
				for(i = 0; i<40; i++){
					if(boite_pions[i].x == nx + 1 && boite_pions[i].y == ny - 1 && boite_pions[i].color != boite_pions[num_pion].color){
						for(k=2; k<=j; k++){ 
							for(i = 0; i<40; i++){
								if(boite_pions[i].x == nx+k && boite_pions[i].y == ny-k){
									printf("Déplacement interdit, il y a plusieurs pions sur la diagonale\n");
									return 0;
								}
							}
							
						}
						emplacement_vide.x = (boite_pions[num_pion].x)*get_pion_size();
						emplacement_vide.y = (boite_pions[num_pion].y)*get_pion_size();
						emplacement_vide.w = get_pion_size();
						emplacement_vide.h = get_pion_size();

						
						SDL_RenderFillRect(renderer, &emplacement_vide);
						SDL_RenderPresent(renderer);

						emplacement_vide.x = (boite_pions[i].x)*get_pion_size();
						emplacement_vide.y = (boite_pions[i].y)*get_pion_size();
						emplacement_vide.w = get_pion_size();
						emplacement_vide.h = get_pion_size();

						
						SDL_RenderFillRect(renderer, &emplacement_vide);
						SDL_RenderPresent(renderer);

						boite_pions[num_pion].x = nx;
						boite_pions[num_pion].y = ny;
						draw_pion(renderer, &boite_pions[num_pion], tex_n, tex_b, tex_dn, tex_db);

						/* place le pion mangé en (-1,-1) en dehors du plateau */
						boite_pions[i].x = -1; 
						boite_pions[i].y = -1;
						printf("Vous avez mangé le pion adverse n°%d\n", i);
						return 0;
					}
				}

				emplacement_vide.x = (boite_pions[num_pion].x)*get_pion_size();
				emplacement_vide.y = (boite_pions[num_pion].y)*get_pion_size();
				emplacement_vide.w = get_pion_size();
				emplacement_vide.h = get_pion_size();
				SDL_RenderFillRect(renderer, &emplacement_vide);
				SDL_RenderPresent(renderer);
				boite_pions[num_pion].x = nx;
				boite_pions[num_pion].y = ny;
				draw_pion(renderer, &boite_pions[num_pion], tex_n, tex_b, tex_dn, tex_db);
				printf("Déplacement de %d cases\n", j);
				return 0;


			}
			if(nx == boite_pions[num_pion].x + j && ny == boite_pions[num_pion].y - j){
				for(i = 0; i<40; i++){
					if(boite_pions[i].x == nx - 1 && boite_pions[i].y == ny + 1 && boite_pions[i].color != boite_pions[num_pion].color){
						for(k=2; k<=j; k++){ 
							for(i = 0; i<40; i++){
								if(boite_pions[i].x == nx-k && boite_pions[i].y == ny+k){
									printf("Déplacement interdit, il y a plusieurs pions sur la diagonale\n");
									return 0;
								}
							}
							
						}
						emplacement_vide.x = (boite_pions[num_pion].x)*get_pion_size();
						emplacement_vide.y = (boite_pions[num_pion].y)*get_pion_size();
						emplacement_vide.w = get_pion_size();
						emplacement_vide.h = get_pion_size();

						
						SDL_RenderFillRect(renderer, &emplacement_vide);
						SDL_RenderPresent(renderer);

						emplacement_vide.x = (boite_pions[i].x)*get_pion_size();
						emplacement_vide.y = (boite_pions[i].y)*get_pion_size();
						emplacement_vide.w = get_pion_size();
						emplacement_vide.h = get_pion_size();

						
						SDL_RenderFillRect(renderer, &emplacement_vide);
						SDL_RenderPresent(renderer);

						boite_pions[num_pion].x = nx;
						boite_pions[num_pion].y = ny;
						draw_pion(renderer, &boite_pions[num_pion], tex_n, tex_b, tex_dn, tex_db);

						/* place le pion mangé en (-1,-1) en dehors du plateau */
						boite_pions[i].x = -1; 
						boite_pions[i].y = -1;
						printf("Vous avez mangé le pion adverse n°%d\n", i);
						return 0;
					}
				}

				emplacement_vide.x = (boite_pions[num_pion].x)*get_pion_size();
				emplacement_vide.y = (boite_pions[num_pion].y)*get_pion_size();
				emplacement_vide.w = get_pion_size();
				emplacement_vide.h = get_pion_size();
				SDL_RenderFillRect(renderer, &emplacement_vide);
				SDL_RenderPresent(renderer);
				boite_pions[num_pion].x = nx;
				boite_pions[num_pion].y = ny;
				draw_pion(renderer, &boite_pions[num_pion], tex_n, tex_b, tex_dn, tex_db);
				printf("Déplacement de %d cases\n", j);
				return 0;


			}
			if(nx == boite_pions[num_pion].x + j && ny == boite_pions[num_pion].y + j){
				for(i = 0; i<40; i++){
					if(boite_pions[i].x == nx - 1 && boite_pions[i].y == ny - 1 && boite_pions[i].color != boite_pions[num_pion].color){
						for(k=2; k<=j; k++){ 
							for(i = 0; i<40; i++){
								if(boite_pions[i].x == nx-k && boite_pions[i].y == ny-k){
									printf("Déplacement interdit, il y a plusieurs pions sur la diagonale\n");
									return 0;
								}
							}
							
						}
						emplacement_vide.x = (boite_pions[num_pion].x)*get_pion_size();
						emplacement_vide.y = (boite_pions[num_pion].y)*get_pion_size();
						emplacement_vide.w = get_pion_size();
						emplacement_vide.h = get_pion_size();

						
						SDL_RenderFillRect(renderer, &emplacement_vide);
						SDL_RenderPresent(renderer);

						emplacement_vide.x = (boite_pions[i].x)*get_pion_size();
						emplacement_vide.y = (boite_pions[i].y)*get_pion_size();
						emplacement_vide.w = get_pion_size();
						emplacement_vide.h = get_pion_size();

						
						SDL_RenderFillRect(renderer, &emplacement_vide);
						SDL_RenderPresent(renderer);

						boite_pions[num_pion].x = nx;
						boite_pions[num_pion].y = ny;
						draw_pion(renderer, &boite_pions[num_pion], tex_n, tex_b, tex_dn, tex_db);

						/* place le pion mangé en (-1,-1) en dehors du plateau */
						boite_pions[i].x = -1; 
						boite_pions[i].y = -1;
						printf("Vous avez mangé le pion adverse n°%d\n", i);
						return 0;
					}
				}

				emplacement_vide.x = (boite_pions[num_pion].x)*get_pion_size();
				emplacement_vide.y = (boite_pions[num_pion].y)*get_pion_size();
				emplacement_vide.w = get_pion_size();
				emplacement_vide.h = get_pion_size();
				SDL_RenderFillRect(renderer, &emplacement_vide);
				SDL_RenderPresent(renderer);
				boite_pions[num_pion].x = nx;
				boite_pions[num_pion].y = ny;
				draw_pion(renderer, &boite_pions[num_pion], tex_n, tex_b, tex_dn, tex_db);
				printf("Déplacement de %d cases\n", j);
				return 0;
			}
		}
	}

	SDL_DestroyTexture(tex_n);
	SDL_DestroyTexture(tex_b);
	SDL_DestroyTexture(tex_dn);
	SDL_DestroyTexture(tex_db);
	return 0;

}

pion *init_game(SDL_Renderer *renderer){

	int ln, cn;
	int cpt = 0; /* compteur de pions */

	pion* boite_pions = NULL;

    SDL_Texture * tex_n = NULL;
    SDL_Texture * tex_b = NULL;
    SDL_Texture * tex_db = NULL;
    SDL_Texture * tex_dn = NULL;

    tex_n = load_texture_pion("pionNoir2.bmp", renderer);
    tex_b = load_texture_pion("pionBlanc2.bmp", renderer);
	tex_dn = load_texture_pion("dameNoir4.bmp", renderer);
	tex_db = load_texture_pion("dameBlanc4.bmp", renderer);

    boite_pions = malloc(sizeof(pion)*40);

	for (cn = 0; cn <= 9; cn+=2)
	{
		for (ln = 0; ln<=3 ; ln ++)
		{
			boite_pions[cpt].x = cn+(ln+1)%2;
			boite_pions[cpt].y = ln;
			boite_pions[cpt].color = 0;
			boite_pions[cpt].dame = 0;
			affiche_pion2(renderer, &boite_pions[cpt], tex_n);
			cpt ++;
		}
	}

	for (cn = 0; cn <= 9; cn+=2)
	{
		for (ln = 6; ln<=9 ; ln ++)
		{
			boite_pions[cpt].x = cn+(ln+1)%2;
			boite_pions[cpt].y = ln;
			boite_pions[cpt].color = 1;
			boite_pions[cpt].dame = 0;
			affiche_pion2(renderer, &boite_pions[cpt], tex_b);
			cpt ++;
		}
	}

	SDL_DestroyTexture(tex_b);
	SDL_DestroyTexture(tex_n);
	SDL_DestroyTexture(tex_db);
	SDL_DestroyTexture(tex_dn);


	return boite_pions;

}

int *deplace_p(pion *boite_pions)
{
    
    int compteur_clic;
    int i;
    int ind_x;
    int ind_y;
    int c_x;
    int c_y;
    int tab[] = {-1,-1,-1};
    compteur_clic = 0;
    
    while(compteur_clic <= 2){
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0 ) {
        	/*
        	if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT){
            	compteur_clic ++;
            }
            */
            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && compteur_clic < 1)
            {
                SDL_GetMouseState( &c_x, &c_y );
                /*
                printf("Les coordonnees de la souris sont (x,y) = (%d,%d)\n", c_x,c_y);
                */
                ind_x = c_x/get_pion_size();
                ind_y = c_y/get_pion_size();
                /*
                printf("Les coordonnees convertis sont (x,y) = (%d,%d)\n", ind_x,ind_y);
                */
                for (i = 0; i < 40 ; i++)
                {
                	/*
                    printf(" la valeur de i c'est %d\n", i);
                    */
                    if (boite_pions[i].x == ind_x && boite_pions[i].y == ind_y)
                    {
                    	compteur_clic ++;
                        tab[2] = i;
                        /*
                        printf("La valeur dans tab[2] = %d qui est le numero de la case \n", tab[2]);
                        printf("La valeur dans tab[2] = %d qui est le numero de la case \n", i);
                        printf("On a clique sur un pion\n");
                        */
                    }
                    /*
                    if (boite_pions[i].x != ind_x && boite_pions[i].y != ind_y)
                    {
                        printf("Vous n'avez pas cliqué sur un pion\n");
                    }
                    */
                }
                if(tab[2] == -1){
                	printf("vous n'avez pas cliqué sur un pion\n");
                }
                /*
                printf("C'est le contenu du tableau pour l'instant\n");
                printf("valeur dans tab[0] = %d\n", tab[0]);
                printf("valeur dans tab[1] = %d\n", tab[1]);
                printf("valeur dans tab[2] = %d\n", tab[2]);
                */
                printf("Vous avez selectionné le pion numero %d\n", tab[2]);
            }

            
    /* lors du deuxieme clic */
            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && compteur_clic >= 1)
            {   
            	/*     
                printf(" nombre de clic pour le moment  = %d (on s'attend a avoir 2)\n", compteur_clic);
                */
                SDL_GetMouseState( &c_x, &c_y );
                /*
                printf(" coordonnees du deuxieme clic \nx position = %d, y position =%d\n", c_x,c_y);
                */
                ind_x = c_x/get_pion_size();
                ind_y = c_y/get_pion_size();
                /*
                printf("indice ligne et de colonne du deuxieme clic (%d, %d)\n", ind_x, ind_y);
                */
                tab[0] = ind_x;
                tab[1] = ind_y;
                /*
                printf("On stocke les valeurs des nouveaux indices ils sont dans tab[0] et tab[1]\n");
                printf("valeur dans tab[0] = %d\n", tab[0]);
                printf("valeur dans tab[1] = %d\n", tab[1]);
                printf(" nombre de clic pour le moment  = %d (on s'attend a avoir 2)\n", compteur_clic);
                */
                compteur_clic ++;
            }
        }
    }
    
    /* while(compteur_clic <= 3){
     SDL_Event e;
     while (SDL_PollEvent(&e) != 0 ) {
         if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
             compteur_clic = compteur_clic + 1;
     }
     }*/
    while(compteur_clic > 2 && compteur_clic <= 2){
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0 ) {
            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
            {
            	/*
            	printf("nombre de clic pour le moment  = %d (on s'attend a avoir 3 puis 4 puis 5)\n", compteur_clic);
            	*/
            	compteur_clic = compteur_clic + 1;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && compteur_clic == 10){
            	/*
                printf("C'est bon ca suffit les cliques calme toi maintenant !! Con de ta race\n");
              */

        	}
        }

    }
    if(tab[0] != -1){
    	printf("Déplacement du pion numero %d en (%d,%d)\n", tab[2], tab[0], tab[1]);	
    }

    return tab;
}
