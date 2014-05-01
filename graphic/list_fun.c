/*
** list_fun.c for list_fun in /home/thibaut.lopez/Lem-In/graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Mon Apr 28 12:06:49 2014 Thibaut Lopez
** Last update Thu May  1 11:43:14 2014 Thibaut Lopez
*/

#include "graphic.h"

int	greater_x(t_lem *list, int *scale)
{
  int    save;

  save = 0;
  while (list)
    {
      if (list->ptr.x > save)
	save = list->ptr.x;
      list = list->next;
    }
  if (1635 <= save)
    return (-1);
  *scale = save / 327 + 1;
  save *= 50 / *scale;
  return ((save >= 1000) ? save + (50 / *scale) : 1000);
}

int	greater_y(t_lem *list, int *scale)
{
  int    save;

  save = 0;
  while (list)
    {
      if (list->ptr.y > save)
	save = list->ptr.y;
      list = list->next;
    }
  if (1635 <= save)
    return (-1);
  *scale = save / 327 + 1;
  save *= 50 / *scale;
  return ((save >= 1000) ? save + (50 / *scale) : 1000);
}

t_lem	*find_elem_in_list(char *name, t_lem *list)
{
  while (list)
    {
      if (strcmp(name, list->name) == 0)
	return (list);
      list = list->next;
    }
  return (NULL);
}
