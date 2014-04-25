/*
** parse_arc.c for parse_arc in /home/alex-odet/work/Lem-In/parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Wed Apr 23 10:35:38 2014 alex-odet
** Last update Fri Apr 25 13:57:16 2014 alex-odet
*/

#include "lem_in.h"

t_arc		*parse_arc(t_lem *list, int *i, char **map)
{
  int		j;
  t_arc		*arc;
  char		**tmp_tab;

  arc = NULL;
  while (map[*i])
    {
      j = 0;
      tmp_tab = my_str_to_wordtab(map[*i], "-");
      check_len_tab(tmp_tab);
      is_valid(tmp_tab[0], tmp_tab[1]);
      *i = *i + 1;
    }
  return (arc);
}

void		check_len_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  if (i != 2)
    {
      printf("Bad definition of the arc.\n");
      exit(EXIT_FAILURE);
    }
}

t_arc		*is_valid(char *first, char *second, t_lem *list)
{
  t_arc	*arc_list;
  int	x;
  t_lem	*cur;
  char	*save_first;
  char	*save_second;

  save_first = NULL;
  arc_list = NULL;
  save_second = NULL; 
  cur = list;
  while (list)
    {
      if (strcmp(first, list->name) == 0)
	save_first = strdup(first);
      list = list->next;
    }
  if (save_first == NULL)
    bad_arc(first);
  while (cur)
    {
      if (strcmp(second, cur->name) ==0)
	save_second = strdup(second);
      cur = cur->next;
    }
  if (save_second == NULL)
    bad_arc(second);
}
