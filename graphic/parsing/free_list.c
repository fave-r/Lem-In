/*
** free_list.c for free_list in /Users/Alex/work/Lem-In
** 
** Made by Alex
** Login   <Alex@epitech.net>
** 
** Started on  Tue Apr 29 15:01:35 2014 Alex
** Last update Wed Apr 30 12:33:53 2014 Alex
*/

#include "lem_in.h"

void		free_list(t_lem *list)
{
  t_lem *to_free;

  while (list != NULL)
    {
      to_free = list;
      list = list->next;
      free(to_free->name);
      free(to_free);
    }
}

void		free_arc(t_arc *arc)
{
  t_arc		*to_free;

  while (arc != NULL)
    {
      to_free = arc;
      arc = arc->next;
      free(to_free->first);
      free(to_free->second);
      free(to_free);
    }
}
