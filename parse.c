/*
** parse.c for parse in /Users/Alex/work/Lem-In
** 
** Made by Alex
** Login   <Alex@epitech.net>
** 
** Started on  Wed Apr 30 16:09:14 2014 Alex
** Last update Wed Apr 30 16:23:59 2014 Alex
*/

#include "lem_in.h"

t_all	*parse(char **map)
{
  int	i;
  t_all	*list;

  i = 1;
  list = xmalloc(sizeof(t_all));
  list->room = parse_room(map, &i);
  list->room = fill_list_num(list->room);
  list->arc = parse_arc(list->room, &i, map);
  if (list->arc == NULL)
    no_arc();
  list->arc = arc_num(list->arc, list->room);
  list->move = NULL;
  return (list);
}
