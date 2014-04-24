/*
** graphic.h for graphic in /home/thibaut.lopez/Lem-In/graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Thu Apr 24 15:45:29 2014 Thibaut Lopez
** Last update Thu Apr 24 18:24:13 2014 Thibaut Lopez
*/

#ifndef GRAPHIC_H
#define GRAPHIC_H
#define BPP(S)	(S)->format->BytesPerPixel

#include <math.h>
#include <SDL/SDL.h>

typedef struct	s_box
{
  SDL_Surface	*ret;
  double	error;
  double	x;
  double	y;
  double	cx;
  double	cy;
}		t_box;

SDL_Surface	*draw_circle(Uint32 pixel);

#endif
