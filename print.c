/*
** print.c for lem_in in /home/thibaud/rendu/Lem-In
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Thu Apr 17 05:55:27 2014 thibaud
** Last update Thu Apr 17 06:01:37 2014 thibaud
*/

#include "lem_in.h"

int     print_arc_tab(int **arc_tab, int size)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (j < size)
    {
      i = 0;
      while (i < size)
        {
          printf("%d ", arc_tab[j][i]);
          i++;
        }
      printf("\n");
      j++;
    }
  return (0);
}

int     print_dijsktra(t_graphe *graphe, int end, int start)
{
  t_list        *cur;

  cur = get_sommet(graphe, end);
  while (cur->numero_sommet != start)
    {
      printf("%d-%d\n", cur->numero_sommet, cur->last);
      cur = get_sommet(graphe, cur->last);
    }
  return (0);
}
