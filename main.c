/*
** main.c for lem_in in /home/thibaud/rendu/lem_in
**
** Made by thixbaud
** Login   <thibaud@epitech.net>
**
** Started on  Sat Apr 12 23:46:01 2014 thibaud
** Last update Wed Apr 23 16:30:00 2014 alex-odet
*/

#include "lem_in.h"

void		my_show_room(t_lem *list);

int		main(__attribute__((unused))int ac,
		     __attribute__((unused))char **av)
{
  t_graphe	*graphe;
  t_way		*ways;
  int		start;
  int		end;
  int		nb_fourmis;
  t_lem		*list;
  //  t_arc		*arc;
  char		**map;

  ways = NULL;
  map = NULL;
  map = init_parse();
  if (map == NULL)
    {
      printf("No map.\n");
      exit(EXIT_FAILURE);
    }
  int i =  0;
  while (map[i])
    printf("la map vaut : %s\n", map[i++]);
  nb_fourmis = parse_ants(map[0]);
  list = parse_room(map);
  map = NULL;
  if (list == NULL)
    {
      printf("No rooms in the map.\n");
      exit(EXIT_FAILURE);
    }
  my_show_room(list);
  start = 1;
  end = my_list_size(list);
  /*  arc = parse_arc();
      if (arc == NULL)
      {
      printf("No rooms are linked.\n");
      exit(EXIT_FAILURE);
      }
  */
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
      printf("room->%s\tx->%d\ty->%d\n", list->name, list->ptr.x, list->ptr.y);
      list = list->next;
    }
}
