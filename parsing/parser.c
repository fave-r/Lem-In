/*
** parser.c for parser in /home/alex-odet/work/Lem-In/parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Thu Apr 17 16:54:23 2014 alex-odet
** Last update Fri Apr 18 17:08:58 2014 alex-odet
*/

#include "lem_in.h"

t_lem		*parsing()
{
  int	ants;
  t_lem	*list;
  t_arc	*ptr;

  ants = parse_ants();
  list = parse_room();
}

int	parse_ants()
{
  int	ants;
  char	*tmp;

  tmp = get_next_line(0);
  if (tmp[0] <= '0' || tmp[0] >= '9' || tmp[0] != '-')
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

t_lem	*parse_room()
{
  char	**tab;
  char	*tmp;
  t_lem	*list;
  int	bool_start;
  int	bool_end;

  list = NULL;
  bool_start = 0;
  bool_end = 0;
  while ((tmp = get_next_line(0)))
    {
      if ((strcmp(tmp, "##start") == 0) || (tmp[0] == '#' && tmp[1] != '#'))
	{
	  bool_start = 1;
	  tmp = get_next_line(0);
	  tab = my_str_to_wordtab(tmp);
	  check_tab(tab);
	  list = my_put_in_lem_list(list, strdup(tab[0]), atoi(tab[1]), atoi(tab[2]));
	}
      else
	{
	  tab = my_str_to_wordtab(tmp);
	  check_tab(tab);
	  list = my_put_in_lem_list(list, strdup(tab[0]), atoi(tab[1]), atoi(tab[2]));
	}
      else if (strcmp(tmp, "##end") == 0)
	{
	  bool_end = 1;
	  tmp = get_next_line(0);
	  tab = my_str_to_wordtab(tmp);
	  check_tab(tab);
	  list = my_put_in_lem_list(list, strdup(tab[0]), atoi(tab[1]), atoi(tab[2]));
	  return (list);
	}
    }
  if (bool_start != 1)
    no_start();
  if (bool_end != 1)
    no_end();
  return (list);
}

void	no_start()
{
  printf("Syntax error : No entry in the map.\n");
  exit(EXIT_FAILURE);
}

void	no_end()
{
  printf("Syntax error : No end in the map.\n");
  exit(EXIT_FAILURE);
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
	  if ((tab[i][j] <= '0' || tab[i][j] >= '9') || (tab[i][j] == '-' && j != 0))
	    bad_coor();
	  j++;
	}
      i++;
    }
}

void	bad_coor()
{
  printf("Syntax error in coor values.\n");
  exit(EXIT_FAILURE);
}

void	bad_len()
{
  printf("Syntax error in room description.\n");
  exit(EXIT_FAILURE);
}
