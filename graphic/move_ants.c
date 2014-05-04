/*
** move_ants.c for move_ants in /home/thibaut.lopez/Lem-In/graphic
**
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
**
** Started on  Thu May  1 16:33:43 2014 Thibaut Lopez
** Last update Sun May  4 13:25:59 2014 romaric
*/

#include "graphic.h"

void	edit_cpy(t_all *all, SDL_Surface *cpy, int *i)
{
  t_mov		*tmp;
  t_lem		*lem;
  t_ant		*cur;
  SDL_Rect	rect;
  int		len;

  *i = (*i == 6) ? 1 : *i;
  tmp = all->move->ptr;
  while (tmp != NULL)
    {
      cur = find_ant_in_list(tmp->ant_num, all->ant);
      if (cur == NULL)
	exit(printf("Ant not found\n"));
      lem = find_elem_in_list(tmp->whereis, all->room);
      if (lem == NULL)
	exit(printf("Room not found\n"));
      len = POS(lem->ptr.x, all->scale) - POS(cur->ant_x, all->scale);
      rect.x = POS(cur->ant_x, all->scale) + (len * *i / 5) - 7;
      len = POS(lem->ptr.y, all->scale) - POS(cur->ant_y, all->scale) - 10;
      rect.y = POS(cur->ant_y, all->scale) + (len * *i / 5) - 5;
      if (*i == 5)
	{
	  cur->ant_x = lem->ptr.x;
	  cur->ant_y = lem->ptr.y;
	}
      SDL_BlitSurface(all->image, NULL, cpy, &rect);
      tmp = tmp->next;
    }
}

void	keep_init_value(SDL_Surface *cpy, SDL_Surface *screen, SDL_Rect *init)
{
  int	x;
  int	y;

  x = init->x;
  y = init->y;
  SDL_BlitSurface(cpy, NULL, screen, init);
  init->x = x;
  init->y = y;
  SDL_Flip(screen);
}

void	move_ants(SDL_Surface *screen
		  , SDL_Surface *arena, SDL_Rect *pos, t_all *all)
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
      edit_cpy(all, cpy, &i);
      keep_init_value(cpy, screen, &init);
      if (operate_event(screen, cpy, &init, pos) == 1)
	return;
      SDL_BlitSurface(arena, NULL, cpy, NULL);
      i++;
      if (i > 5)
	all->move = all->move->next;
    }
  all->move = tmp;
}
