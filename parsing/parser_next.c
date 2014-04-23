/*
** parser_next.c for lem-in in /home/blackbird/work/Lem-In/parsing
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sat Apr 19 14:25:15 2014 romaric
** Last update Wed Apr 23 16:14:35 2014 alex-odet
*/

#include "lem_in.h"

t_lem	*parse_room_start(int *bool_start, t_lem *list, char *map)
{
  char	**tab;

  if (map != NULL)
    {
      *bool_start = 1;
      tab = my_str_to_wordtab(map, "\t ");
      printf("start\n");
      check_tab(tab);
      list = my_put_start(list, strdup(tab[0]), atoi(tab[1]), atoi(tab[2]));
      return (list);
    }
  return (NULL);
}

t_lem	*parse_room_end(int *bool_end, t_lem *list, char *map)
{
  char	**tab;

  if (map != NULL)
    {
      *bool_end = 1;
      printf("end\n");
      tab = my_str_to_wordtab(map, " \t");
      check_tab(tab);
      list = my_put_end(list, strdup(tab[0]), atoi(tab[1]), atoi(tab[2]));
      return (list);
    }
  return (NULL);
}

t_lem	*parse_room_other(t_lem *list, char *tmp)
{
  char	**tab;

  printf("tmp = %s\n", tmp);
  tab = my_str_to_wordtab(tmp, "\t \n\0");
  int	i;
  i = 0;
  while (tab[i])
    printf("les coordonnées sont : %s\n", tab[i++]);
  check_tab(tab);
  list = my_put_in_lem_list(list, strdup(tab[0]), atoi(tab[1]), atoi(tab[2]));
  return (list);
}
