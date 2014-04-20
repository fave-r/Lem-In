/*
** my_put_in_lem_list.c for my_put_in_lem_list in /home/alex-odet/work/Lem-In/parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Apr 18 14:45:17 2014 alex-odet
** Last update Sun Apr 20 17:34:48 2014 alex-odet
*/

#include "lem_in.h"

t_lem		*new_node(char *name, int x, int y)
{
  t_lem		*new;

  new = xmalloc(sizeof(t_lem));
  new->name = strdup(name);
  new->ptr.x = x;
  new->ptr.y = y;
  new->next = NULL;
  return (new);
}

t_lem		*my_put_in_lem_list(t_lem *list, char *name, int x, int y)
{
  t_lem		*tmp;

  if (list == NULL)
    return (new_node(name, x, y));
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_node(name, x, y);
  return (list);
}

t_lem		*my_put_start(t_lem *list, char *name, int x, int y)
{
  t_lem		*tmp;

  list->is_start = 1;
  if (list == NULL)
    return(new_node(name, x, y));
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_node(name, x, y);
  return (list);
}

t_lem		*my_put_end(t_lem *list, char *name, int x, int y)
{
  t_lem		*tmp;

  list->is_start = 2;
  if (list == NULL)
    return(new_node(name, x, y));
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_node(name, x, y);
  return (list);
}
