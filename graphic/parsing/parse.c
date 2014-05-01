/*
** parse.c for parse in /Users/Alex/work/Lem-In
** 
** Made by Alex
** Login   <Alex@epitech.net>
** 
** Started on  Wed Apr 30 16:09:14 2014 Alex
** Last update Wed Apr 30 20:29:20 2014 Thibaut Lopez
*/

#include "graphic.h"

void	parse(t_all *list)
{
  int	i;

  i = 1;
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
}
