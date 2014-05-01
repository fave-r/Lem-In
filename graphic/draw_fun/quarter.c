/*
** quarter.c for quarter in /home/thibaut.lopez/MUL_2013_wolf3d/useful_fun
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Jan  8 18:41:17 2014 Thibaut Lopez
** Last update Thu May  1 01:24:20 2014 Thibaut Lopez
*/

#include "graphic.h"

void	quarter1(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b, int *delta)
{
  int	x;
  int	y;
  int	coef;

  x = a->x;
  y = a->y;
  coef = delta[0];
  delta[0] = coef << 1;
  delta[1] = delta[1] << 1;
  while (x != b->x)
    {
      put_pixel(arena, x++, y, 0xFFFFFF);
      coef -= delta[1];
      if (coef <= 0)
	{
	  y++;
	  coef += delta[0];
	}
    }
}

void	quarter2(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b, int *delta)
{
  int	x;
  int	y;
  int	coef;

  x = a->x;
  y = a->y;
  coef = delta[1];
  delta[0] = delta[0] << 1;
  delta[1] = coef << 1;
  while (y != b->y)
    {
      put_pixel(arena, x, y++, 0xFFFFFF);
      coef -= delta[0];
      if (coef <= 0)
	{
	  x++;
	  coef += delta[1];
	}
    }
}

void	quarter3(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b, int *delta)
{
  int	x;
  int	y;
  int	coef;

  x = a->x;
  y = a->y;
  coef = delta[1];
  delta[1] = coef << 1;
  delta[0] = delta[0] << 1;
  while (y != b->y)
    {
      put_pixel(arena, x, y++, 0xFFFFFF);
      coef += delta[0];
      if (coef <= 0)
	{
	  x--;
	  coef += delta[1];
	}
    }
}

void	quarter4(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b, int *delta)
{
  int	x;
  int	y;
  int	coef;

  x = a->x;
  y = a->y;
  coef = delta[0];
  delta[0] = coef << 1;
  delta[1] = delta[1] << 1;
  while (x != b->x)
    {
      put_pixel(arena, x--, y, 0xFFFFFF);
      coef += delta[1];
      if (coef >= 0)
	{
	  y++;
	  coef += delta[0];
	}
    }
}
