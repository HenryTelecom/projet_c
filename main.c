#include <stdio.h>

#include <SDL2/SDL.h>

#include "window.h"
#include "damier.h"
#include "pion.h"

int main()
{
    /*int pi =0;*/
    int nb_click = 0;
	int quit = 0;
    SDL_Event e;
    /*pion *p;*/
    pion *boite_pions;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer;
    int *resultat_click;
    renderer = create_window(window);



    create_damier(window, renderer);
    boite_pions = init_game(renderer);



    /*p = create_pion(1,0,0);
    draw_pion(renderer, &p[0]);*/

    /*for(pi = 0; pi < 100; pi++){
        printf("pion %d coord : x = %d y = %d, color = %d, dame = %d\n", pi, boite_pions[pi].x, boite_pions[pi].y, boite_pions[pi].color, boite_pions[pi].dame);
    }*/
    while(nb_click <= 100){
        resultat_click = deplace_p(boite_pions);
        move_pion(renderer,resultat_click[2],&boite_pions[0],resultat_click[0],resultat_click[1]);
        nb_click ++;
    }

    /*move_pion(renderer,7,&boite_pions[0],4,5);
    move_pion(renderer,3,&boite_pions[0],1,4);
    move_pion(renderer,3,&boite_pions[0],2,5);
    move_pion(renderer,2,&boite_pions[0],2,3);
    move_pion(renderer,2,&boite_pions[0],3,4);
    move_pion(renderer,11,&boite_pions[0],5,4);
    move_pion(renderer,11,&boite_pions[0],6,5);
    move_pion(renderer,6,&boite_pions[0],4,3);
    move_pion(renderer,6,&boite_pions[0],5,4);
    move_pion(renderer,5,&boite_pions[0],3,2);
    move_pion(renderer,5,&boite_pions[0],4,3);
    move_pion(renderer,0,&boite_pions[0],2,1);
    move_pion(renderer,0,&boite_pions[0],3,2);
    move_pion(renderer,20,&boite_pions[0],0,5);
    move_pion(renderer,20,&boite_pions[0],1,4);
    move_pion(renderer,20,&boite_pions[0],0,3);
    move_pion(renderer,20,&boite_pions[0],1,2);
    move_pion(renderer,20,&boite_pions[0],0,1);
    move_pion(renderer,20,&boite_pions[0],1,0);*/

    /*for(pi = 0; pi < 100; pi++){
        printf("pion %d coord : x = %d y = %d, color = %d, dame = %d\n", pi, boite_pions[pi].x, boite_pions[pi].y, boite_pions[pi].color, boite_pions[pi].dame);
    }*/
    free(boite_pions);

    while( !quit ) {
    	/*Handle events on queue*/
        while( SDL_PollEvent( &e ) != 0 )
        {
            /*User requests quit*/
            if( e.type == SDL_QUIT )
            {
                quit = 1;
            }
        }
    }

    return 0;
}

