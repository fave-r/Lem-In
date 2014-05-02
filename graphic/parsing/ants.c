/*
** ants.c for ants in /Users/Alex/work/Lem-In/graphic/parsing
** 
** Made by Alex
** Login   <Alex@epitech.net>
** 
** Started on  Thu May  1 16:08:13 2014 Alex
** Last update Fri May  2 16:48:22 2014 Thibaut Lopez
*/

#include "graphic.h"

t_ant	*ants(int nb_ants, t_lem *room)
{
  t_ant	*ptr;

  ptr = NULL;
  ptr = fill_ant_num(ptr, nb_ants, room);
  return (ptr);
}

t_ant	*fill_ant_num(t_ant *ptr, int nb, t_lem *room)
{
  int	i;
  int	x;
  int	y;

  i = 1;
  while (room->is_start != 1)
    room = room->next;
  x = room->ptr.x;
  y = room->ptr.y;
  while (i <= nb)
    {
      ptr = create_list(ptr, i, x, y);
      i++;
    }
  return (ptr);
}

t_ant	*node(int nb, int x, int y)
{
  t_ant	*new;

  new = xmalloc(sizeof(t_ant));
  new->num = nb;
  new->ant_x = x;
  new->ant_y = y;
  new->next = NULL;
  return (new);
}

t_ant	*create_list(t_ant *ptr, int nb, int x, int y)
{
  t_ant	*tmp;

  if (ptr == NULL)
    return (node(nb, x, y));
  tmp = ptr;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = node(nb, x, y);
  return (ptr);
}
