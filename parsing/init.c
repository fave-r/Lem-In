/*
** init.c for init in /home/alex-odet/work/Lem-In/parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Wed Apr 23 14:02:21 2014 alex-odet
** Last update Wed Apr 23 16:31:01 2014 alex-odet
*/

#include "lem_in.h"

char	**init_parse()
{
  char	*tmp;
  char	**map;

  map = NULL;
  while ((tmp = get_next_line(0)))
    {
      map = my_strscat(map, tmp);
      free(tmp);
    }
  return (map);
}
