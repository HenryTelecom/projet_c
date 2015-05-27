#include "son.h"

void deplace_pion()
{
   Mix_Music *musique; 
	SDL_WM_SetCaption("SDL_Mixer", NULL);
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) 
   {
      printf("%s", Mix_GetError());
   }

   musique = Mix_LoadMUS("deplace_pion.mp3"); 
   Mix_PlayMusic(musique, 1); 
   
}

void mange_pion()
{
   Mix_Music *musique; 
	SDL_WM_SetCaption("SDL_Mixer", NULL);
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) 
   {
      printf("%s", Mix_GetError());
   }

   musique = Mix_LoadMUS("mange_pion.mp3"); 
   Mix_PlayMusic(musique, 1); 
   
}

void dame()
{
   Mix_Music *musique; 
	SDL_WM_SetCaption("SDL_Mixer", NULL);
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) 
   {
      printf("%s", Mix_GetError());
   }
   musique = Mix_LoadMUS("dame.mp3"); 
   Mix_PlayMusic(musique, 1); 
}
void fin_de_partie()
{
   Mix_Music *musique; 
	SDL_WM_SetCaption("SDL_Mixer", NULL);
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) 
   {
      printf("%s", Mix_GetError());
   }

   musique = Mix_LoadMUS("fin_de_partie.mp3"); 
   Mix_PlayMusic(musique, -1); 
}
void initialisation()
{
   Mix_Music *musique; 
	SDL_WM_SetCaption("SDL_Mixer", NULL);
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) 
   {
      printf("%s", Mix_GetError());
   }

   musique = Mix_LoadMUS("initialisation.mp3"); 
   Mix_PlayMusic(musique, 1); Mix_FreeMusic(musique); 
}
//	Mix_FreeMusic(musique); 
// 	Mix_CloseAudio(); 
