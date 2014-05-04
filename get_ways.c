/*
** get_ways.c for lem_in in /home/thibaud/rendu/Lem-In
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Sat Apr 19 23:11:03 2014 thibaud
** Last update Sun May  4 13:10:38 2014 romaric
*/

#include "lem_in.h"

int             kill_link(t_graphe *graphe, int s1, int s2)
{
  t_list        *cur;

  cur = get_sommet(graphe, s1);
  rmv_adjacent(cur, s2);
  cur->nb_sommet_adjacent--;
  cur = get_sommet(graphe, s2);
  rmv_adjacent(cur, s1);
  cur->nb_sommet_adjacent--;
  return (0);
}

t_way           *get_ways(t_graphe *graphe, int start, int end, t_way *ways)
{
  while (dijkstra(graphe, start, end))
    {
      ways = get_solution(graphe, ways, end, start);
      kill_the_way(graphe, ways, start, end);
    }
  if (ways == NULL)
    {
      printf("Pas de chemin\n");
      exit(-1);
    }
  return (ways);
}

t_way           *get_solution(t_graphe *graphe, t_way *list_chemins,
                              int end, int start)
{
  t_list        *cur;
  t_way         *new;

  new = malloc(sizeof (t_way));
  new->len = 0;
  new->chemin = NULL;
  if (!graphe)
    return (NULL);
  cur = get_sommet(graphe, end);
  while (cur && cur->numero_sommet != start)
    {
      new->chemin = realloc(new->chemin, (new->len + 1) * sizeof (int));
      new->chemin[new->len] = cur->numero_sommet;
      cur = get_sommet(graphe, cur->last);
      new->len++;
    }
  new->chemin = realloc(new->chemin, (new->len + 1) * sizeof (int));
  new->chemin[new->len] = cur->numero_sommet;
  new->len++;
  new->len_th = new->len - 1;
  new->nb_fourmies = 0;
  new->next = list_chemins;
  my_rev_tab(new->chemin, new->len);
  return (new);
}

int             kill_the_way(t_graphe *graphe
			     , t_way *to_kill, int start, int end)
{
  int           i;
  t_list        *cur;

  cur = graphe->next;
  i = 1;
  while (i < to_kill->len)
    {
      if (get_sommet(graphe, to_kill->chemin[i - 1])->numero_sommet != start
	  && get_sommet(graphe, to_kill->chemin[i - 1])->numero_sommet != end)
	get_sommet(graphe
		   , to_kill->chemin[i - 1])->nb_sommet_adjacent = 0;
      else if (get_sommet(graphe
			  , to_kill->chemin[i - 1])->numero_sommet == start
	       && get_sommet(graphe, to_kill->chemin[i])->numero_sommet == end)
	kill_link(graphe, to_kill->chemin[i], to_kill->chemin[i - 1]);
      i++;
    }
  while (cur != NULL)
    kill_the_way_next(&cur);
  if (get_sommet(graphe, start))
    {
      get_sommet(graphe, start)->fix = 0;
      get_sommet(graphe, start)->distance = 0;
    }
  return (0);
}

t_lem		*get_lem(t_lem *list, int numero_fourmi)
{
  t_lem		*tmp;

  tmp = list;
  while (tmp->ptr.num != numero_fourmi)
    tmp = tmp->next;
  return (tmp);
}
