/*
** init.c for init in /home/alex-odet/work/Lem-In/parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Wed Apr 23 14:02:21 2014 alex-odet
** Last update Mon Apr 28 17:48:18 2014 Alex
*/

#include "lem_in.h"

char	**init_parse()
{
  char	*tmp;
  char	**map;
  char	**tmp_tab;

  map = NULL;
  tmp_tab = NULL;
  while ((tmp = get_next_line(0)))
    {
      tmp_tab = my_strscat(map, tmp);
      map = tmp_tab;
    }
  return (map);
}
