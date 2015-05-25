#include <stdio.h>

#include <SDL2/SDL.h>

#include "window.h"
#include "damier.h"
#include "pion.h"

int event_loop(SDL_Window *window, SDL_Renderer *renderer, pion *boite_pions);
void draw_scene(SDL_Window *window, SDL_Renderer *renderer, pion *boite_pions);

int main()
{
    SDL_Window *window = NULL;

    SDL_Renderer *renderer = create_window(window);

    pion *boite_pions = init_game();

    draw_scene(window, renderer, boite_pions);


    return event_loop(window, renderer, boite_pions);
}

void draw_scene(SDL_Window *window, SDL_Renderer *renderer, pion *boite_pions)
{
    SDL_SetRenderDrawColor(renderer, 255, 204, 153, 255);

    SDL_RenderClear(renderer);

    draw_damier(window, renderer);
    draw_pions(renderer, boite_pions);

    SDL_RenderPresent(renderer);

}

int event_loop(SDL_Window *window, SDL_Renderer *renderer, pion *boite_pions)
{
    SDL_Event e;

    int quit = 0,
        x, y;

    pion *selected_pion = NULL,
         *tmp_pion = NULL;


    while(!quit) {
        while(SDL_PollEvent(&e) != 0)
        {
            switch(e.type)
            {
                case SDL_MOUSEBUTTONDOWN :
                    x = (int) (e.button.x / get_pion_size());
                    y = (int) (e.button.y / get_pion_size());

                    tmp_pion = pion_at_coord(boite_pions, x, y);

                    if (selected_pion && !tmp_pion && pion_can_move_at(selected_pion, x, y)) {
                        printf("MOVING PION : %d, %d TO : %d, %d\n", selected_pion->x, selected_pion->y, x, y);
                        selected_pion->x = x;
                        selected_pion->y = y;

                        draw_scene(window, renderer, boite_pions);

                        selected_pion = NULL;
                    } else if (tmp_pion) {
                        if (!selected_pion) {
                            printf("SELECT PION : %d, %d\n", tmp_pion->x, tmp_pion->y);
                            selected_pion = tmp_pion;
                        } else if (tmp_pion->x == selected_pion->x && tmp_pion->y == selected_pion->y ){
                            printf("UNSELECT PION : %d, %d\n", selected_pion->x, selected_pion->y);
                            selected_pion = NULL;
                        }
                    }

                    break;

                case SDL_QUIT :
                    quit = 1;
                    break;
            }
        }
    }

    return 0;
}
