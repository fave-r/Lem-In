/*
** print.c for lem_in in /home/thibaud/rendu/Lem-In
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Thu Apr 17 05:55:27 2014 thibaud
** Last update Thu May  1 16:28:06 2014 thibaud
*/

#include "lem_in.h"

int             print_wave(t_fourmi *fourmis)
{
  t_fourmi      *cur;

  cur = fourmis;
  while (cur)
    {
      if (cur->posy <= cur->len)
        printf("P%d-%d", cur->numero_fourmi, cur->chemin[cur->posy + 1]);
      if (cur->next)
	printf(" ");
      cur->posy++;
      cur = cur->next;
    }
  return (0);
}

int		print_arc_tab(int **arc_tab, int size)
{
  int		i;
  int		j;

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

int		print_dijsktra(t_graphe *graphe, int end, int start)
{
  t_list	*cur;

  cur = get_sommet(graphe, end);
  while (cur->numero_sommet != start)
    {
      printf("%d-%d\n", cur->numero_sommet, cur->last);
      cur = get_sommet(graphe, cur->last);
    }
  return (0);
}

int             print_result(t_way *way)
{
  int           i;

  i = 0;
  if (way == NULL)
    return (0);
  printf("Nb_fourmie =\t%d\nLen = %d\n", way->nb_fourmies, way->len);
  printf("Result\t");
  while (i < way->len)
    {
      printf("%d-", way->chemin[i]);
      i++;
    }
  printf("\n");
  printf("len_th :\t%d\n", way->len_th);
  printf("len :\t%d\n\n", way->len);
  return (0);
}

int             print_all_result(t_way *ways)
{
  t_way         *cur;

  cur = ways;
  while (cur)
    {
      print_result(cur);
      cur = cur->next;
    }
  return (0);
}
