/*
** pixel_fun.c for pixel_fun in /home/thibaut.lopez/Lem-In/graphic/draw_fun
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Thu May  1 00:15:28 2014 Thibaut Lopez
** Last update Thu May  1 00:56:03 2014 Thibaut Lopez
*/

#include "graphic.h"

void	put_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
  Uint8	*p;

  p = (Uint8 *)surface->pixels + y * surface->pitch + x * BPP(surface);
  if (BPP(surface) == 1)
    *p = pixel;
  else if (BPP(surface) == 2)
    *(Uint16 *)p = pixel;
  else if (BPP(surface) == 3)
    {
      p[0] = (SDL_BYTEORDER == SDL_BIG_ENDIAN) ?
	(pixel >> 16) & 0xff : pixel & 0xff;
      p[1] = (pixel >> 8) & 0xff;
      p[2] = (SDL_BYTEORDER == SDL_BIG_ENDIAN) ?
	pixel & 0xff : (pixel >> 16) & 0xff;
    }
  else if (BPP(surface) == 4)
    *(Uint32 *)p = pixel;
}

Uint32	get_pixel(SDL_Surface *surface, int x, int y)
{
  Uint32	*p;

  p = (Uint32 *)surface->pixels;
  return (p[(y * surface->w) + x]);
}
