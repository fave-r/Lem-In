/*
** main.c for lem_in in /home/thibaud/rendu/lem_in
**
** Made by thixbaud
** Login   <thibaud@epitech.net>
**
** Started on  Sat Apr 12 23:46:01 2014 thibaud
** Last update Mon Apr 28 17:11:59 2014 Alex
*/

#include "lem_in.h"

void		my_show_room(t_lem *list);
void		my_show_arc(t_arc *list);

int		main(__attribute__((unused))int ac,
		     __attribute__((unused))char **av)
{
  int		i;
  t_graphe	*graphe;
  t_way		*ways;
  int		start;
  int		end;
  int		nb_fourmis;
  t_lem		*list;
  t_arc		*arc;
  char		**map;

  ways = NULL;
  map = NULL;
  map = init_parse();
  if (map == NULL)
    {
      printf("No map.\n");
      exit(EXIT_FAILURE);
    }
  i = 1;
  nb_fourmis = parse_ants(map[0]);
  list = parse_room(map, &i);
  start = 1;
  end = my_list_size(list);
  list = fill_list_num(list);
  arc = parse_arc(list, &i, map);
  if (arc == NULL)
    {
      printf("No rooms are linked.\n");
      exit(EXIT_FAILURE);
    }
  arc = arc_num(arc, list);
  my_show_arc(arc);
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
  sfree(map);
  return (0);
}

void		my_show_room(t_lem *list)
{
  while (list)
    {
      printf("room->%s\tnum->%d\tx->%d\ty->%d\n", list->name,list->ptr.num,  list->ptr.x, list->ptr.y);
      list = list->next;
    }
}

void		my_show_arc(t_arc *list)
{
  while (list)
    {
      printf("room : %s (Num : %d) is linked to : %s (Num : %d)\n", list->first, list->first_room, list->second, list->second_room);
      list = list->next;
    }
}
