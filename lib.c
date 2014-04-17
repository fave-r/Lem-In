/*
** lib.c for lem-in in /home/blackbird/work/Lem-In
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Thu Apr 17 16:23:44 2014 romaric
** Last update Thu Apr 17 16:31:44 2014 romaric
*/

#include "lem_in.h"

void	*my_memset(void *source, int size, int nb)
{
  char	*new;
  int	i;

  i = 0;
  new = source;
  while (i < size)
    {
      new[i] = nb;
      i++;
    }
  return (new);
}

void	*my_xdup(void *source, int size)
{
  char	*tmp;
  char	*src;
  int	i;

  i = 0;
  src = source;
  if ((tmp = malloc(sizeof(char) * size)) == NULL)
    exit(0);
  while (i < size)
    {
      tmp[i] = src[i];
      i++;
    }
  tmp = (void *)tmp;
  return (tmp);
}

int	my_xcopy(void *source, int len_src, void *target, int len_trg)
{
  char	*src;
  char	*trg;
  int	i;

  i = 0;
  src = source;
  trg = target;
  while (i < len_src && i < len_trg)
    {
      trg[i] = src[i];
      i++;
    }
  return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = (str && str[0] == '-') ? -1 : 1;
  while (!my_isdigit(str[i]))
    if (str && str[0] == '-')
      i++;
  while (*(str + i) >= '0' && *(str + i) <= '9')
    {
      j = (10 * j) + (str[i] - 48);
      i++;
    }
  j *= k;
  return (j);
}

int	my_rev_tab(int *tab, int len)
{
  int	i;
  int	tmp;

  i = 0;
  while (i < len)
    {
      tmp = tab[i];
      tab[i] = tab[len - 1];
      tab[len - 1] = tmp;
      i++;
      len--;
    }
  return (0);
}
