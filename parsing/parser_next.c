/*
** parser_next.c for lem-in in /home/blackbird/work/Lem-In/parsing
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sat Apr 19 14:25:15 2014 romaric
** Last update Fri May  2 16:41:11 2014 romaric
*/

#include "lem_in.h"

t_lem	*parse_room_start(int *bool_start, t_lem *list, char *map)
{
  char	**tab;

  if (map != NULL)
    {
      *bool_start = *bool_start + 1;
      tab = my_str_to_wordtab(map, "\t ");
      check_tab(tab);
      list = my_put_start(list, strdup(tab[0]), atoi(tab[1]), atoi(tab[2]));
      sfree(tab);
      return (list);
    }
  return (NULL);
}

t_lem	*parse_room_end(int *bool_end, t_lem *list, char *map)
{
  char	**tab;

  if (map != NULL)
    {
      *bool_end = *bool_end + 1;
      tab = my_str_to_wordtab(map, " \t");
      check_tab(tab);
      list = my_put_end(list, strdup(tab[0]), atoi(tab[1]), atoi(tab[2]));
      sfree(tab);
      return (list);
    }
  return (NULL);
}

t_lem	*parse_room_other(t_lem *list, char *tmp)
{
  char	**tab;

  tab = my_str_to_wordtab(tmp, "\t \n\0");
  check_tab(tab);
  list = my_put_in_lem_list(list, strdup(tab[0]), atoi(tab[1]), atoi(tab[2]));
  sfree(tab);
  return (list);
}

void	parse_room_next(int *bool_start, int *bool_end, t_lem **list)
{
  *list = NULL;
  *bool_start = 0;
  *bool_end = 0;
}
