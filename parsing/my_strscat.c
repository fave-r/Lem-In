/*
** my_strscat.c for my_strscat in /home/alex-odet/work/Lem-In/parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Wed Apr 23 13:11:55 2014 alex-odet
** Last update Wed Apr 23 17:00:12 2014 alex-odet
*/

#include "lem_in.h"

void	sfree(char **tab)
{
  int	i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  if (tab != NULL)
    free(tab);
}

char	*my_strdup(char *src)
{
  char	*dest;

  dest = xmalloc(sizeof(char) * (strlen(src) + 1));
  strcpy(dest, src);
  dest[strlen(src) + 1] = 0;
  return (dest);
}

int	my_strslen(char **tab)
{
  int	i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    i++;
  return (i);
}

char	**my_strscat(char **tab, char *str)
{
  char	**new;
  int	i;

  new = xmalloc(sizeof(char *) * (my_strslen(tab) + 2));
  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      new[i] = /*my_*/strdup(tab[i]);
      i++;
    }
  new[i] = /*my_*/strdup(str);
  new[i + 1] = NULL;
  sfree(tab);
  return (new);
}
