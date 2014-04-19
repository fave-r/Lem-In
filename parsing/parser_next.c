/*
** parser_next.c for lem-in in /home/blackbird/work/Lem-In/parsing
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sat Apr 19 14:25:15 2014 romaric
** Last update Sat Apr 19 14:40:26 2014 romaric
*/

#include "lem_in.h"

void	parse_room_start(int *bool_start, t_lem *list)
{
  char	*tmp;
  char	**tab;

  *bool_start = 1;
  tmp = get_next_line(0);
  tab = my_str_to_wordtab(tmp);
  check_tab(tab);
  list = my_put_in_lem_list(list, strdup(tab[0]), atoi(tab[1]), atoi(tab[2]));
}

t_elem	parse_room_end(int *bool_end, t_lem *list)
{
  bool_end = 1;
  tmp = get_next_line(0);
  tab = my_str_to_wordtab(tmp);
  check_tab(tab);
  list = my_put_in_lem_list(list, strdup(tab[0]), atoi(tab[1]), atoi(tab[2]));
  return (list);
}

void	parse_room(t_lem *list)
{
  tab = my_str_to_wordtab(tmp);
  check_tab(tab);
  list = my_put_in_lem_list(list, strdup(tab[0]), atoi(tab[1]), atoi(tab[2]));
}
