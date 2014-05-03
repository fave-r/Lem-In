/*
** init_tubes.c for init_tubes in /home/thibaut.lopez/Lem-In/graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Apr 30 17:09:40 2014 Thibaut Lopez
** Last update Fri May  2 21:08:26 2014 Thibaut Lopez
*/

#include "graphic.h"

void	init_tubes(t_arc *arc, t_lem *room, SDL_Surface *arena, int scale)
{
  t_arc		*tmp;
  SDL_Rect	a;
  SDL_Rect	b;
  t_lem		*start;
  t_lem		*end;

  tmp = arc;
  while (tmp != NULL)
    {
      start = find_elem_in_list(tmp->first, room);
      if (start == NULL)
	exit(printf("Room not found\n"));
      a.x = start->ptr.x * (50 / scale);
      a.y = start->ptr.y * (50 / scale);
      end = find_elem_in_list(tmp->second, room);
      if (end == NULL)
	exit(printf("Room not found\n"));
      b.x = end->ptr.x * (50 / scale);
      b.y = end->ptr.y * (50 / scale);
      draw_tubes(&a, &b, arena, scale);
      tmp = tmp->next;
    }
}

void	init_circle(t_lem *room, SDL_Surface *arena, int scale)
{
  Uint32	pixel;
  t_lem		*tmp;

  tmp = room;
  while (tmp != NULL)
    {
      if (tmp->is_start == 0)
	pixel = 0xFFFFFF;
      else if (tmp->is_start == 1)
	pixel = 0xFF0000;
      else
	pixel = 0x00FF00;
      printf("%s => %d\n", tmp->name, tmp->is_start);
      draw_circle(pixel, arena, &(tmp->ptr), scale);
      tmp = tmp->next;
    }
}
