/*
** dijkstra.c for lem_in in /home/thibaud/rendu/Lem-In
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Thu Apr 17 05:59:54 2014 thibaud
** Last update Thu Apr 17 05:59:56 2014 thibaud
*/

#include "lem_in.h"

int     dijkstra(t_graphe *graphe, int start, int end)
{
  int           **arc_tab;
  t_list        *tmp;

  if (!graphe || !get_sommet(graphe, start) || !get_sommet(graphe, end))
    exit(-1);
  arc_tab = build_arcs_tab(graphe, start);
  tmp = fix_sommet(graphe);
  while (get_sommet(graphe, end)->fix == 0 && tmp != NULL)
    {
      get_tmp_distance(graphe, tmp, arc_tab);
      tmp = fix_sommet(graphe);
    }
  if (tmp == NULL)
    return (0);
  return (1);
}

t_list          *fix_sommet(t_graphe *graphe)
{
  t_list        *cur;
  int           closest_sommet;
  int           closest_distance;

  closest_sommet = -1;
  closest_distance = INT_MAX;
  cur = graphe->next;
  while (cur != NULL)
    {
      if (cur->fix == 0 && cur->distance < closest_distance)
        {
          closest_distance = cur->distance;
          closest_sommet = cur->numero_sommet;
        }
      cur = cur->next;
    }
  if (closest_distance != INT_MAX)
    get_sommet(graphe, closest_sommet)->fix = 1;
  return (get_sommet(graphe, closest_sommet));
}

int     get_tmp_distance(t_graphe *graphe, t_list *fix, int **arc_tab)
{
  int   i;

  i = 0;
  while (fix && i < fix->nb_sommet_adjacent)
    {
      if (get_sommet(graphe, fix->adjacents[i])->distance >
          (fix->distance + arc_tab[fix->numero_sommet - 1]
           [fix->adjacents[i] - 1]))
        {
          get_sommet(graphe, fix->adjacents[i])->distance =
            fix->distance + arc_tab[fix->numero_sommet - 1]
            [fix->adjacents[i] - 1];
          get_sommet(graphe, fix->adjacents[i])->last = fix->numero_sommet;
        }
      i++;
    }
  return (0);
}

int     **build_arcs_tab(t_graphe *graphe, int start)
{
  int   **tab;
  int   size;
  int   i;
  int   j;

  i = 0;
  size = get_max_sommet(graphe);
  tab = malloc(sizeof (int *) * size);
  while (i < size)
    {
      j = 0;
      tab[i] = malloc(sizeof (int) * size);
      while (j < size)
        {
          tab[i][j] = arc_exist(graphe, i + 1, j + 1) ? 1 : 0;
          j++;
        }
      i++;
    }
  get_sommet(graphe, start)->distance = 0;
  return (tab);
}
