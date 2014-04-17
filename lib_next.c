/*
** lib_next.c for lem-in in /home/blackbird/work/Lem-In
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Thu Apr 17 16:32:15 2014 romaric
** Last update Thu Apr 17 16:43:21 2014 romaric
*/

#include "lem_in.h"

int		get_max_sommet(t_graphe *graphe)
{
  t_list	*cur;
  int		max;

  max = -1;
  cur = graphe->next;
  while (cur != NULL)
    {
      if (cur->numero_sommet > max)
        max = cur->numero_sommet;
      cur = cur->next;
    }
  return (max);
}

t_list		*get_sommet(t_graphe *graphe, int nb)
{
  t_list	*cur;

  cur = graphe->next;
  while (cur != NULL)
    {
      if (cur->numero_sommet == nb)
        return (cur);
      cur = cur->next;
    }
  return (NULL);
}

int		my_isdigit(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int		rmv_adjacent(t_list *cur, int s2)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (j < cur->nb_sommet_adjacent)
    {
      if (cur->adjacents[j] == s2)
        j++;
      cur->adjacents[i] = cur->adjacents[j];
      i++;
      j++;
    }
  return (0);
}
