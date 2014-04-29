/*
** parser.c for parser in /home/alex-odet/work/Lem-In/parsing
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Thu Apr 17 16:54:23 2014 alex-odet
** Last update Tue Apr 29 14:08:12 2014 romaric
*/

#include "lem_in.h"

int	parse_ants(char *tab)
{
  int	ants;

  if ((tab[0] < '0' || tab[0] > '9') && tab[0] != '-')
    {
      printf("Syntax error : no number of ants.\n");
      exit(EXIT_FAILURE);
    }
  else
    ants = atoi(tab);
  if (ants <= 0)
    bad_ants();
  return (ants);
}

t_lem	*loop_parse(t_lem **list, char *tab)
{
  char	**tmp_tab;

  tmp_tab = my_str_to_wordtab(tab, "\t \n");
  if (tab[0] != '#' && tmp_tab[2] != NULL
      && strcmp(tmp_tab[2], "-") != 0)
    *list = parse_room_other(*list, tab);
  else
    return (*list);
  return (*list);
}

t_lem	*parse_room(char **tab, int *i)
{
  t_lem	*list;
  int	bool_start;
  int	bool_end;

  list = NULL;
  bool_start = 0;
  bool_end = 0;
  while (tab[*i] != NULL && (tab[*i][1] != '-' && tab[*i][2] != '-'))
    {
      if (strcmp(tab[*i], "##start") == 0)
	{
	  list = parse_room_start(&bool_start, list, tab[*i + 1]);
	  *i = *i + 2;
	}
      if (strcmp(tab[*i], "##end") == 0)
	{
	  list = parse_room_end(&bool_end, list, tab[*i + 1]);
	  *i = *i + 2;
	}
      else
	{
	  list = loop_parse(&list, tab[*i]);
	  *i = *i + 1;
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
  if (tab[i] != NULL)
    while (tab[i] != NULL && tab != NULL)
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
