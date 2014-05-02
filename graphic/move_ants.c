/*
** move_ants.c for move_ants in /home/thibaut.lopez/Lem-In/graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Thu May  1 16:33:43 2014 Thibaut Lopez
** Last update Thu May  1 19:59:52 2014 Thibaut Lopez
*/

#include "graphic.h"

void	edit_cpy(t_all *all, SDL_Surface *cpy, int i)
{
  t_mov		*tmp;
  t_lem		*lem;
  t_ant		*cur;
  SDL_Rect	rect;

  i = (i == 6) ? 1 : i;
  tmp = all->move->coucou;
  while (tmp != NULL)
    {
      cur = find_ant_in_list(tmp->ant_num, all->ant);
      lem = find_elem_in_list(tmp->whereis, all->room);
      rect.x = (cur->ant_x - lem->ptr.x) * i / 5 + lem->ptr.x;
      rect.y = (cur->ant_y - lem->ptr.y) * i / 5 + lem->ptr.y;
      SDL_BlitSurface(all->image, NULL, cpy, &rect);
      tmp = tmp->next;
    }
}

void	move_ants(SDL_Surface *screen, SDL_Surface *arena, SDL_Rect *pos, t_all *all)
{
  t_round	*tmp;
  SDL_Surface	*cpy;
  SDL_Rect	init;
  int		i;

  init.x = 0;
  init.y = 0;
  tmp = all->move;
  cpy = SDL_CreateRGBSurface(SDL_SWSURFACE, pos->x, pos->y, 32, 0, 0, 0, 0);
  SDL_BlitSurface(arena, NULL, cpy, NULL);
  i = 1;
  while (all->move != NULL)
    {
      edit_cpy(all, cpy, i)
      SDL_BlitSurface(cpy, NULL, screen, &init);
      if (operate_event(screen, cpy, &init, pos) == 1)
	return;
      SDL_BlitSurface(arena, NULL, cpy, NULL);
      i++;
      if (i > 5)
	all->move = all->move->next;
    }
}
