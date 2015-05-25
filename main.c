#include <stdio.h>
#include <SDL2/SDL.h>
#include "window.h"
#include "damier.h"
#include "pion.h"
#include "son.h"


int main()
{
    /*

    int pi =0;
    pion *p;

    
    int nb_click = 0;
    */
    int *resultat_click;
    
    pion *boite_pions;
    int quit = 0;
    SDL_Event e;
    SDL_Surface *icon = 0;


    SDL_Window *window = NULL;
    SDL_Renderer *renderer;
    icon = SDL_LoadBMP("dameBlanc4.bmp");


    /*p = create_pion(1,0,0);
    draw_pion(renderer, &p[0]);*/

    renderer = create_window(window);
    SDL_SetWindowIcon(window, icon);
    SDL_FreeSurface(icon);

    create_damier(window, renderer);
 

    boite_pions = init_game(renderer);





    /*for(pi = 0; pi < 100; pi++){
        printf("pion %d coord : x = %d y = %d, color = %d, dame = %d\n", pi, boite_pions[pi].x, boite_pions[pi].y, boite_pions[pi].color, boite_pions[pi].dame);
    }*/
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

    while( !quit ) {
    	/*Handle events on queue*/
        while( SDL_PollEvent( &e ) != 0 )
        {
            
            /*User requests quit*/
            if( e.type == SDL_QUIT )
            {
                quit = 1;
            }
            resultat_click = deplace_p(boite_pions);
            move_pion(renderer,resultat_click[2],&boite_pions[0],resultat_click[0],resultat_click[1]);
        }
    }

    return 0;
}

