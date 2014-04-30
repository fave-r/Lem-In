/*
** main.c for lem_in in /home/thibaud/rendu/lem_in
**
** Made by thixbaud
** Login   <thibaud@epitech.net>
**
** Started on  Sat Apr 12 23:46:01 2014 thibaud
** Last update Wed Apr 30 16:23:04 2014 Alex
*/

#include "lem_in.h"

void		show_room(t_lem *list);

int		main(void)
{
  int		ants;
  char		**map;
  t_all		*p;

  map = init_parse();
  if (map == NULL)
    no_map();
  ants = parse_ants(map[0]);
  p = parse(map);
  my_show_map(map);
  algo(p->arc, p->room, ants);
  sfree(map);
  free_arc(p->arc);
  free_list(p->room);
  return (0);
}

void		my_show_map(char **map)
{
  int		i;

  i = 0;
  while (map != NULL && map[i])
    printf("%s\n", map[i++]);
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
