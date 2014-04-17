/*
** main.c for lem_in in /home/thibaud/rendu/lem_in
** 
** Made by thixbaud
** Login   <thibaud@epitech.net>
** 
** Started on  Sat Apr 12 23:46:01 2014 thibaud
** Last update Thu Apr 17 06:03:53 2014 thibaud
*/

#include "lem_in.h"

void    *my_memset(void *source, int size, int nb)
{
  char  *new;
  int   i;

  i = 0;
  new = source;
  while (i < size)
    {
      new[i] = nb;
      i++;
    }
  return (new);
}

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

int		my_isdigit(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int     my_getnbr(char *str)
{
  int   i;
  int   j;
  int   k;

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

/* int	kill_the_way(t_graphe *graphe) */
/* { */

/*   return (0); */
/* } */

/* t_way	*get_solution(t_graphe *graphe, t_way *tab_ways) */
/* { */
/*   t_way	*new; */

/* } */

int		main(int argc, char **argv)
{
  t_graphe	*graphe;
  //t_way		*solutions;

  (void)argc;
  (void)argv;
  graphe = new_graphe();
  insert_arc(graphe, 1, 2);
  insert_arc(graphe, 1, 3);
  insert_arc(graphe, 1, 4);
  insert_arc(graphe, 2, 5);
  insert_arc(graphe, 3, 6);
  insert_arc(graphe, 4, 6);
  insert_arc(graphe, 6, 7);
  //solutions = NULL;
  while (dijkstra(graphe, 1, 7))
    {
      //tab_ways = get_solution(graphe, tab_ways);
      print_dijsktra(graphe, 7, 1);
    }
  //if (tab_ways == NULL)
    printf("Pas de solution\n");

  return (0);
}
