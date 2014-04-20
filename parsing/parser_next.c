/*
** parser_next.c for lem-in in /home/blackbird/work/Lem-In/parsing
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sat Apr 19 14:25:15 2014 romaric
** Last update Sun Apr 20 19:45:05 2014 alex-odet
*/

#include "lem_in.h"

t_lem	*parse_room_start(int *bool_start, t_lem *list)
{
  char	*tmp;
  char	**tab;

  *bool_start = 1;
  tmp = get_next_line(0);
  tab = my_str_to_wordtab(tmp, "\t ");
  check_tab(tab);
  list = my_put_start(list, strdup(tab[0]), atoi(tab[1]), atoi(tab[2]));
  return (list);
}

t_lem	*parse_room_end(int *bool_end, t_lem *list)
{
  char	*tmp;
  char	**tab;

  *bool_end = 1;
  tmp = get_next_line(0);
  tab = my_str_to_wordtab(tmp, " \t");
  check_tab(tab);
  list = my_put_end(list, strdup(tab[0]), atoi(tab[1]), atoi(tab[2]));
  return (list);
}

t_lem	*parse_room_other(t_lem *list, char *tmp)
{
  char	**tab;

  tab = my_str_to_wordtab(tmp, "\t ");
  check_tab(tab);
  list = my_put_in_lem_list(list, strdup(tab[0]), atoi(tab[1]), atoi(tab[2]));
  return (list);
}
