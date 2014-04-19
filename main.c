/*
** main.c for lem_in in /home/thibaud/rendu/lem_in
**
** Made by thixbaud
** Login   <thibaud@epitech.net>
**
** Started on  Sat Apr 12 23:46:01 2014 thibaud
** Last update Sun Apr 20 00:31:34 2014 thibaud
*/

#include "lem_in.h"

int		main(__attribute__((unused))int ac,
		     __attribute__((unused))char **av)
{
  t_graphe	*graphe;
  t_way		*ways;
  int		start;
  int		end;
  int		nb_fourmis;

  ways = NULL;
  nb_fourmis = 5;
  start = 9;
  end = 1;

  graphe = new_graphe();
  
  insert_arc(graphe, 9, 2);
  insert_arc(graphe, 9, 3);
  insert_arc(graphe, 2, 1);
  insert_arc(graphe, 1, 3);
  insert_arc(graphe, 2, 3);

  ways = get_ways(graphe, start, end, ways);
  free_graphe(graphe);
  fill_ways(ways, nb_fourmis);
  run_lem_in(ways);
  free_ways(ways);
  return (0);
}
