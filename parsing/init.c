/*
** init.c for init in /home/alex-odet/work/Lem-In/parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Wed Apr 23 14:02:21 2014 alex-odet
** Last update Wed Apr 30 14:09:01 2014 Alex
*/

#include "lem_in.h"

char	**init_parse()
{
  char		*tmp;
  char		**map;
  char		**tmp_tab;
  size_t	len;
  int       	getlen;

  map = NULL;
  tmp_tab = NULL;
  len = 10;
  tmp = xmalloc(sizeof(char) * len);
  while ((getlen = getline(&tmp, &len, stdin)) > 0)
    {
      tmp[getlen - 1] = 0;
      printf("gnl tmp = %s\n", tmp);
      tmp_tab = my_strscat(map, tmp);
      map = tmp_tab;
      free(tmp);
      tmp = xmalloc(sizeof(char) * len);
    }
  sfree(tmp_tab);
  free(tmp);
  return (map);
}
