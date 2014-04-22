/*
** parser.c for parser in /home/alex-odet/work/Lem-In/parsing
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Thu Apr 17 16:54:23 2014 alex-odet
** Last update Tue Apr 22 13:01:50 2014 alex-odet
*/

#include "lem_in.h"

int	parse_ants(void)
{
  int	ants;
  char	*tmp;

  tmp = get_next_line(0);
  if ((tmp[0] < '0' || tmp[0] > '9' ) && tmp[0] != '-')
    {
      printf("Syntax error : no number of ants.\n");
      exit(EXIT_FAILURE);
    }
  else
    ants = atoi(tmp);
  if (ants <= 0)
    bad_ants();
  return (ants);
}

t_lem	*parse_room(void)
{
  char	**tmp_tab;
  char	*tmp;
  t_lem	*list;
  int	bool_start;
  int	bool_end;

  list = NULL;
  bool_start = 0;
  bool_end = 0;
  while ((tmp = get_next_line(0)))
    {
      printf("tmp = %s\n", tmp);
      if (tmp != NULL)
	{
	  tmp_tab = my_str_to_wordtab(tmp, "\t \n");
	  if (strcmp(tmp, "##start") == 0)
	    list = parse_room_start(&bool_start, &(*list));
	  else if (strcmp(tmp, "##end") == 0)
	    list = parse_room_end(&bool_end, &(*list));
	  else if (tmp[0] != '#' && tmp_tab[2] != NULL && strcmp(tmp_tab[2], "-") != 0)
	    list = parse_room_other(&(*list), tmp);
	  else
	    return (list);
	}
    }
  if (bool_start != 1)
    no_start();
  if (bool_end != 1)
    no_end();
  return (list);
}

void	check_tab(char **tab)
{
  int	i;
  int	j;
  int	len;

  i = 1;
  len = my_len_tab(tab);
  if (len != 3)
    bad_len();
  while (tab[i] != NULL)
    {
      j = 0;
      while (tab[i][j] != '\0')
	{
	  if ((tab[i][j] < '0' || tab[i][j] > '9')
	      || (tab[i][j] == '-' && j != 0))
	    bad_coor();
	  j++;
	}
      i++;
    }
}
