/*
** draw_tubes.c for draw_tubes in /home/thibaut.lopez/Lem-In/graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Fri Apr 25 11:33:21 2014 Thibaut Lopez
** Last update Sat Apr 26 04:29:00 2014 Thibaut Lopez
*/

#include "graphic.h"

void	draw_tubes(SDL_Rect *f_box, SDL_Rect *s_box, SDL_Surface *arena)
{
  int	i;

  i = 0;
  f_box->x += 15;
  f_box->y += 20;
  s_box->x += 15;
  s_box->y += 20;
  while (i < 12)
    {
      draw_line(f_box, s_box, arena);
      f_box->x++;
      s_box->x++;
      i++;
    }
}
