/*
** init.c for init in /home/alex-odet/work/Lem-In/parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Wed Apr 23 14:02:21 2014 alex-odet
** Last update Wed Apr 30 17:50:33 2014 Alex
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
      if (tmp[getlen - 1] == '\n')
	tmp[getlen - 1] = 0;
      tmp_tab = my_strscat(tmp_tab, tmp);
      map = tmp_tab;
      free(tmp);
      tmp = xmalloc(sizeof(char) * len);
    }
  free(tmp);
  return (map);
}
