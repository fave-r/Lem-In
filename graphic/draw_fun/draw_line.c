/*
** draw_line.c for draw_line in /home/thibaut.lopez/Lem-In/graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Sat Apr 26 01:37:50 2014 Thibaut Lopez
** Last update Thu May  1 01:43:25 2014 Thibaut Lopez
*/

#include "graphic.h"

void	half_circle_right(SDL_Surface *arena, SDL_Rect *a,
			  SDL_Rect *b, int *delta)
{
  if (delta[1] != 0)
    {
      if (delta[1] > 0)
	{
	  if (delta[0] >= delta[1])
	    quarter1(arena, a, b, delta);
	  else
	    quarter2(arena, a, b, delta);
	}
      else
	{
	  if (delta[0] >= -1 * delta[1])
	    quarter8(arena, a, b, delta);
	  else
	    quarter7(arena, a, b, delta);
	}
    }
  else
    flat1(arena, a, b);
}

void	half_circle_left(SDL_Surface *arena, SDL_Rect *a,
			 SDL_Rect *b, int *delta)
{
  if (delta[1] != 0)
    {
      if (delta[1] > 0)
	{
	  if (-1 * delta[0] >= delta[1])
	    quarter4(arena, a, b, delta);
	  else
	    quarter3(arena, a, b, delta);
	}
      else
	{
	  if (delta[0] <= delta[1])
	    quarter5(arena, a, b, delta);
	  else
	    quarter6(arena, a, b, delta);
	}
    }
  else
    flat2(arena, a, b);
}

void	flat_line(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b, int *delta)
{
  if (delta[1] != 0)
    {
      if (delta[1] > 0)
	vert1(arena, a, b);
      else
	vert2(arena, a, b);
    }
}

void	draw_line(SDL_Rect *a, SDL_Rect *b, SDL_Surface *arena)
{
  int	*delta;

  delta = malloc(2 * sizeof(int));
  delta[0] = b->x - a->x;
  delta[1] = b->y - a->y;
  if (delta[0] != 0)
    if (delta[0] > 0)
      half_circle_right(arena, a, b, delta);
    else
      half_circle_left(arena, a, b, delta);
  else
    flat_line(arena, a, b, delta);
  free(delta);
}
