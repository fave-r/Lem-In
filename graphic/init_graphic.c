/*
** init_graphic.c for init_graphic in /home/thibaut.lopez/Corewar/Corewar/vm/Graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 19 09:16:50 2014 Thibaut Lopez
** Last update Thu Apr 24 18:57:59 2014 Thibaut Lopez
*/

#include "graphic.h"

int	my_pause(SDL_Surface *screen, SDL_Surface *tmp)
{
  int		wait;
  SDL_Event	event;
  SDL_Rect	position;

  wait = 0;
  position.x = 0;
  position.y = 0;
  while (wait == 0)
    {
      SDL_WaitEvent(&event);
      if (event.key.keysym.sym == SDLK_ESCAPE)
	return (1);
      else if (event.key.keysym.sym == SDLK_SPACE &&
	       event.type == SDL_KEYDOWN)
	wait = 1;
    }
  return (0);
}

int	init_graphic()
{
  SDL_Rect	position;
  SDL_Surface	*screen;
  SDL_Surface	*arena;
  SDL_Surface	*arena2;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (1);
  //  if (TTF_Init() == -1)
  //return (1);
  if ((screen = SDL_SetVideoMode(1000, 1000, 32, SDL_SWSURFACE)) == NULL)
    return (1);
  SDL_WM_SetCaption("Lem-In", NULL);
  SDL_FillRect(screen, NULL,
	       SDL_MapRGB(screen->format, 150, 150, 150));
  arena = draw_circle(0xFF00FF);
  position.x = 0;
  position.y = 0;
  SDL_BlitSurface(arena, NULL, screen, &position);
  arena2 = draw_circle(0xFF0000);
  position.x = 0;
  position.y = 50;
  SDL_BlitSurface(arena2, NULL, screen, &position);
  SDL_Flip(screen);
  my_pause(screen, arena);
  return (0);
}

int	main()
{
  init_graphic();
  //  pause();
  return (0);
}
