/*
** draw_circle.c for draw_circle in /home/thibaut.lopez/Lem-In/graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Thu Apr 24 09:42:42 2014 Thibaut Lopez
** Last update Thu Apr 24 18:55:33 2014 Thibaut Lopez
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

SDL_Surface	*fill_circle(SDL_Surface *surface, Uint32 pixel, double r)
{
  int		x;
  double	dx;
  double	dy;
  Uint8		*target_pixel_a;
  Uint8		*target_pixel_b;

  dy = 1;
  while (dy <= r)
    {
      dx = floor(sqrt((2.0 * r * dy) - (dy * dy)));
      x = 25.0 - dx;
      target_pixel_a = (Uint8 *)surface->pixels +
	((int)(25.0 + r - dy)) * surface->pitch + x * BPP(surface);
      target_pixel_b = (Uint8 *)surface->pixels +
	((int)(25.0 - r + dy)) * surface->pitch + x * BPP(surface);
      while (x <= 25.0 + dx)
        {
	  *(Uint32 *)target_pixel_a = pixel;
	  *(Uint32 *)target_pixel_b = pixel;
	  target_pixel_a += BPP(surface);
	  target_pixel_b += BPP(surface);
	  x++;
        }
      dy += 1.0;
    }
  return (surface);
}

void	init_box(t_box *var)
{
  var->ret = SDL_CreateRGBSurface(SDL_HWSURFACE, 50, 50, 32, 0, 0, 0, 0);
  SDL_FillRect(var->ret, NULL,
	       SDL_MapRGBA(var->ret->format, 255, 255, 255, 255));
  var->error = -20.0;
  var->x = 19.5;
  var->y = 0.5;
  var->cx = 24.5;
  var->cy = 24.5;
}

SDL_Surface	*draw_circle(Uint32 pixel)
{
  t_box	var;

  init_box(&var);
  while (var.x >= var.y)
    {
      put_pixel(var.ret, (int)(var.cx + var.x), (int)(var.cy + var.y), pixel);
      put_pixel(var.ret, (int)(var.cx + var.y), (int)(var.cy + var.x), pixel);
      if (var.x != 0)
        {
	  put_pixel(var.ret, (int)(var.cx - var.x), (int)(var.cy + var.y), pixel);
	  put_pixel(var.ret, (int)(var.cx + var.y), (int)(var.cy - var.x), pixel);
        }
      if (var.y != 0)
        {
	  put_pixel(var.ret, (int)(var.cx + var.x), (int)(var.cy - var.y), pixel);
	  put_pixel(var.ret, (int)(var.cx - var.y), (int)(var.cy + var.x), pixel);
        }
      if (var.x != 0 && var.y != 0)
        {
	  put_pixel(var.ret, (int)(var.cx - var.x), (int)(var.cy - var.y), pixel);
	  put_pixel(var.ret, (int)(var.cx - var.y), (int)(var.cy - var.x), pixel);
        }
      var.error += (++var.y) * 2 - 1;
      var.error -= (var.error >= 0) ? (--var.x) * 2 : 0;
    }
  return (fill_circle(var.ret, pixel, 20.0));
}
