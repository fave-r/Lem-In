/*
** parse.c for parse in /Users/Alex/work/Lem-In
** 
** Made by Alex
** Login   <Alex@epitech.net>
** 
** Started on  Wed Apr 30 16:09:14 2014 Alex
** Last update Wed Apr 30 16:37:33 2014 Alex
*/

#include "lem_in.h"

t_all	*parse()
{
  int	i;
  t_all	*list;

  i = 1;
  list = xmalloc(sizeof(t_all));
  list->map = init_parse();
  if (list->map == NULL)
    no_map();
  list->ants = parse_ants(list->map[0]);
  list->room = parse_room(list->map, &i);
  list->room = fill_list_num(list->room);
  list->arc = parse_arc(list->room, &i, list->map);
  if (list->arc == NULL)
    no_arc();
  list->arc = arc_num(list->arc, list->room);
  list->move = NULL;
  return (list);
}
