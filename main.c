/*
** main.c for lem_in in /home/thibaud/rendu/lem_in
**
** Made by thixbaud
** Login   <thibaud@epitech.net>
**
** Started on  Sat Apr 12 23:46:01 2014 thibaud
** Last update Tue Apr 29 13:56:16 2014 Alex
*/

#include "lem_in.h"

void		my_show_room(t_lem *list);
void		my_show_arc(t_arc *arc);

int		main(void)
{
  int		i;
  int		ants;
  t_lem		*list;
  t_arc		*arc;
  char		**map;

  map = init_parse();
  if (map == NULL)
    no_map();
  i = 1;
  ants = parse_ants(map[0]);
  list = parse_room(map, &i);
  list = fill_list_num(list);
  arc = parse_arc(list, &i, map);
  if (arc == NULL)
    no_arc();
  arc = arc_num(arc, list);
  algo(arc, list, ants);
  sfree(map);
  return (0);
}

void		algo(t_arc *arc, t_lem *list, int ants)
{
  t_graphe	*graphe;
  t_way		*ways;

  ways = NULL;
  graphe = new_graphe();
  while (arc)
    {
      insert_arc(graphe, arc->first_room, arc->second_room);
      arc = arc->next;
    }
  ways = get_ways(graphe, 1, my_list_size(list), ways);
  free_graphe(graphe);
  fill_ways(ways, ants);
  run_lem_in(ways);
  free_ways(ways);
}

void		no_map()
{
  printf("No map.\n");
  exit(EXIT_FAILURE);
}

void		no_arc()
{
  printf("No rooms are linked.\n");
  exit(EXIT_FAILURE);
}
