/*
** init.c for init in /home/alex-odet/work/Lem-In/parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Wed Apr 23 14:02:21 2014 alex-odet
** Last update Wed Apr 23 17:26:39 2014 alex-odet
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
      printf("gnl tmp : %s\n", tmp);
      tmp_tab = my_strscat(map, tmp);
      map = tmp_tab;
    }
  return (map);
}
/*
tmp = strcat(big_buffer, la commande)
  free(big_buffer)
big_buffer = tmp
*/
