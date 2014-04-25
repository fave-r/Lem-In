/*
** my_put_in_arc_list.c for my_put_in_arc_list in /home/alex-odet/work/Lem-In/parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Thu Apr 24 14:13:10 2014 alex-odet
** Last update Fri Apr 25 14:58:28 2014 alex-odet
*/

#include "lem_in.h"

t_arc	*new_arc_node(char *name, char *second)
{
  t_arc	*new;

  new = xmalloc(sizeof(t_arc));
  new->first = strdup(name);
  new->second = strdup(second);
  new->next = NULL;
  return (new);
}

t_arc	*my_put_in_arc_list(t_arc *list, char *first, char *second)
{
  t_arc	*tmp;

  if (list == NULL)
    return (new_arc_node(first, second));
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_arc_node(first, second);
  return (list);
}
