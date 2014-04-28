/*
** arc_num.c for arc_num in /Users/Alex/work/Lem-In/parsing
** 
** Made by Alex
** Login   <Alex@epitech.net>
** 
** Started on  Mon Apr 28 16:57:44 2014 Alex
** Last update Mon Apr 28 17:08:59 2014 Alex
*/

#include "lem_in.h"

t_arc	*arc_num(t_arc *arc, t_lem *list)
{
  t_arc	*tmp;
  t_lem	*new;

  tmp = arc;
  while (tmp)
    {
      new = list;
      while (strcmp(tmp->first, new->name) != 0)
	new = new->next;
      tmp->first_room = new->ptr.num;
      new = list;
      while (strcmp(tmp->second, new->name) != 0)
	new = new->next;
      tmp->second_room = new->ptr.num;
      tmp = tmp->next;
    }
  return (arc);
}
