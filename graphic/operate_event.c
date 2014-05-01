/*
** operate_event.c for operate_event in /home/thibaut.lopez/Lem-In/graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Mon Apr 28 23:48:33 2014 Thibaut Lopez
** Last update Thu May  1 01:42:13 2014 Thibaut Lopez
*/

#include "graphic.h"

void	my_down(SDL_Surface *screen, SDL_Surface *arena,
		SDL_Rect *pos, SDL_Rect *dim)
{
  int		x;
  int		y;
  int		wait;
  SDL_Event	event;

  wait = 0;
  x = pos->x;
  y = pos->y;
  while (wait == 0)
    {
      y -= (dim->y + y - 10 >= 1000) ? 10 : 0;
      pos->y = y;
      pos->x = x;
      SDL_BlitSurface(arena, NULL, screen, pos);
      SDL_Flip(screen);
      usleep(7000);
      if (SDL_PollEvent(&event) != 0 &&
	  event.key.keysym.sym == SDLK_DOWN && event.type == SDL_KEYUP)
	wait = 1;
    }
  pos->y = y;
  pos->x = x;
}

void	my_up(SDL_Surface *screen, SDL_Surface *arena, SDL_Rect *pos)
{
  int		x;
  int		y;
  int		wait;
  SDL_Event	event;

  wait = 0;
  y = pos->y;
  x = pos->x;
  while (wait == 0)
    {
      y += (y + 10 <= 0) ? 10 : 0;
      pos->y = y;
      pos->x = x;
      SDL_BlitSurface(arena, NULL, screen, pos);
      SDL_Flip(screen);
      usleep(7000);
      if (SDL_PollEvent(&event) != 0 &&
	  event.key.keysym.sym == SDLK_UP && event.type == SDL_KEYUP)
	wait = 1;
    }
  pos->y = y;
  pos->x = x;
}

void	my_right(SDL_Surface *screen, SDL_Surface *arena,
		 SDL_Rect *pos, SDL_Rect *dim)
{
  int		y;
  int		x;
  int		wait;
  SDL_Event	event;

  wait = 0;
  x = pos->x;
  y = pos->y;
  while (wait == 0)
    {
      x -= (dim->x + x - 10 >= 1000) ? 10 : 0;
      pos->x = x;
      pos->y = y;
      SDL_BlitSurface(arena, NULL, screen, pos);
      SDL_Flip(screen);
      usleep(7000);
      if (SDL_PollEvent(&event) != 0 &&
	  event.key.keysym.sym == SDLK_RIGHT && event.type == SDL_KEYUP)
	wait = 1;
    }
  pos->x = x;
  pos->y = y;
}

void	my_left(SDL_Surface *screen, SDL_Surface *arena, SDL_Rect *pos)
{
  int		y;
  int		x;
  int		wait;
  SDL_Event	event;

  wait = 0;
  x = pos->x;
  y = pos->y;
  while (wait == 0)
    {
      x += (x + 10 <= 0) ? 10 : 0;
      pos->x = x;
      pos->y = y;
      SDL_BlitSurface(arena, NULL, screen, pos);
      SDL_Flip(screen);
      usleep(7000);
      if (SDL_PollEvent(&event) != 0 &&
	  event.key.keysym.sym == SDLK_LEFT && event.type == SDL_KEYUP)
	wait = 1;
    }
  pos->x = x;
  pos->y = y;
}

int	operate_event(SDL_Surface *screen, SDL_Surface *arena,
		      SDL_Rect *pos, SDL_Rect *dim)
{
  int		wait;
  SDL_Event	event;

  wait = 1;
  while (wait > 0)
    {
      SDL_WaitEvent(&event);
      if (event.key.keysym.sym == SDLK_ESCAPE)
	return (1);
      else if (event.key.keysym.sym == SDLK_DOWN)
	my_down(screen, arena, pos, dim);
      else if (event.key.keysym.sym == SDLK_UP)
	my_up(screen, arena, pos);
      else if (event.key.keysym.sym == SDLK_RIGHT)
	my_right(screen, arena, pos, dim);
      else if (event.key.keysym.sym == SDLK_LEFT)
	my_left(screen, arena, pos);
      if (event.key.keysym.sym == SDLK_SPACE &&
	  event.type == SDL_KEYDOWN)
	wait = (wait == 1) ? 2 : 0;
      /*      else
	      wait = 0;*/
    }
  return (0);
}