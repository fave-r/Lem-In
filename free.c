/*
** free.c for lem_in in /home/thibaud/rendu/Lem-In
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Sat Apr 19 23:55:51 2014 thibaud
** Last update Sun Apr 20 00:02:13 2014 thibaud
*/

#include "lem_in.h"

int             free_arc_tab(int **arc_tab, int size)
{
  int           i;

  i = 0;
  while (i < size)
    {
      free(arc_tab[i]);
      i++;
    }
  free(arc_tab);
  return (0);
}

int		free_graphe(t_graphe *graphe)
{
  t_list        *cur;
  t_list        *tmp;

  cur = graphe->next;
  while (cur)
    {
      tmp = cur;
      cur = cur->next;
      free(tmp->adjacents);
      free(tmp);
    }
  free(graphe);
  return (0);
}

int		free_ways(t_way *ways)
{
  t_way		*cur;
  t_way		*tmp;

  cur = ways;
  while (cur)
    {
      tmp = cur;
      cur = cur->next;
      free(tmp->chemin);
      free(tmp);
    }
  return (0);
}
