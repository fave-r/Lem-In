/*
** line.c for line in /home/thibaut.lopez/MUL_2013_wolf3d/useful_fun
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Jan  8 18:50:50 2014 Thibaut Lopez
** Last update Sat Apr 26 03:02:15 2014 Thibaut Lopez
*/

#include "graphic.h"

void	flat1(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b)
{
  int	x;
  int	y;

  x = a->x;
  y = a->y;
  while (x++ != b->x)
    put_pixel(arena, x, y, 0xFFFFFF);
}

void	flat2(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b)
{
  int	x;
  int	y;

  x = a->x;
  y = a->y;
  while (x-- != b->x)
    put_pixel(arena, x, y, 0xFFFFFF);
}

void	vert1(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b)
{
  int	x;
  int	y;

  x = a->x;
  y = a->y;
  while (y++ != b->y)
    put_pixel(arena, x, y, 0xFFFFFF);
}

void	vert2(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b)
{
  int	x;
  int	y;

  x = a->x;
  y = a->y;
  while (y-- != b->y)
    put_pixel(arena, x, y, 0xFFFFFF);
}
