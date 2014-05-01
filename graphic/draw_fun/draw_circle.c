/*
** draw_circle.c for draw_circle in /home/thibaut.lopez/Lem-In/graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Thu Apr 24 09:42:42 2014 Thibaut Lopez
** Last update Thu May  1 12:29:30 2014 Thibaut Lopez
*/

#include "graphic.h"

void	fill_circle(t_box *var, Uint32 pixel, double r)
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
      x = var->cx + 0.5 - dx;
      target_pixel_a = (Uint8 *)var->ret->pixels
	+ ((int)(var->cy + 0.5 + r - dy)) * var->ret->pitch + x * BPP(var->ret);
      target_pixel_b = (Uint8 *)var->ret->pixels
	+ ((int)(var->cy + 0.5 - r + dy)) * var->ret->pitch + x * BPP(var->ret);
      while (x <= var->cx + 0.5 + dx)
        {
	  *(Uint32 *)target_pixel_a = pixel;
	  *(Uint32 *)target_pixel_b = pixel;
	  target_pixel_a += BPP(var->ret);
	  target_pixel_b += BPP(var->ret);
	  x++;
        }
      dy += 1.0;
    }
}

void	init_box(t_box *var, t_coor *pos, int scale, SDL_Surface *arena)
{
  var->ret = arena;
  var->error = -(20.0 / scale);
  var->x = (20.0 / scale) - 0.5;
  var->y = 0.5;
  var->cx = (double)((pos->x * (50 / scale)) + (25.0 / scale) - 0.5);
  var->cy = (double)((pos->y * (50 / scale)) + (25.0 / scale) - 0.5);
}

void	draw_circle(Uint32 pixel, SDL_Surface *arena, t_coor *pos, int scale)
{
  t_box	var;

  init_box(&var, pos, scale, arena);
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
  fill_circle(&var, pixel, (20.0 / scale));
}
