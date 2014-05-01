/*
** draw_tubes.c for draw_tubes in /home/thibaut.lopez/Lem-In/graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Fri Apr 25 11:33:21 2014 Thibaut Lopez
** Last update Sun Apr 27 21:38:45 2014 Thibaut Lopez
*/

#include "graphic.h"

void	draw_tubes(SDL_Rect *f_box, SDL_Rect *s_box, SDL_Surface *arena)
{
  int	i;
  int	iterat;

  i = 0;
  iterat = ((f_box->x > s_box->x && f_box->y > s_box->y) ||
	    (f_box->x < s_box->x && f_box->y < s_box->y)) ? 1 : -1;
  f_box->x += 25 + iterat * 4;
  f_box->y += 21;
  s_box->x += 25 + iterat * 4;
  s_box->y += 21;
  while (i < 8)
    {
      draw_line(f_box, s_box, arena);
      f_box->x -= iterat;
      s_box->x -= iterat;
      draw_line(f_box, s_box, arena);
      f_box->y++;
      s_box->y++;
      i++;
    }
  f_box->x -= 25 + iterat * 4;
  f_box->y -= 29;
  s_box->x -= 25 + iterat * 4;
  s_box->y -= 29;
}
