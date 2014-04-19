/*
** main.c for lem_in in /home/thibaud/rendu/lem_in
** 
** Made by thixbaud
** Login   <thibaud@epitech.net>
** 
** Started on  Sat Apr 12 23:46:01 2014 thibaud
** Last update Sat Apr 19 22:43:44 2014 thibaud
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

int             my_isdigit(char c)
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

t_way	*get_solution(t_graphe *graphe, t_way *list_chemins, int end, int start)
{
  t_list	*cur;
  t_way	*new;

  new = malloc(sizeof (t_way));
  new->len = 0;
  new->chemin = NULL;
  if (!graphe)
    return (NULL);
  cur = get_sommet(graphe, end);
  while (cur && cur->numero_sommet != start)
    {
      new->chemin = realloc(new->chemin, (new->len + 1) * sizeof (int));
      new->chemin[new->len] = cur->numero_sommet;
      cur = get_sommet(graphe, cur->last);
      new->len++;
    }
  new->chemin = realloc(new->chemin, (new->len + 1) * sizeof (int));
  new->chemin[new->len] = cur->numero_sommet;
  new->len++;
  new->len_th = new->len - 1;
  //new->posy = 0;
  //new->numero_fourmie = 0;
  new->nb_fourmies = 0;
  new->next = list_chemins;
  my_rev_tab(new->chemin, new->len);
  return (new);
}

int	rmv_adjacent(t_list *cur, int s2)
{
  int	i;
  int	j;

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

int	kill_link(t_graphe *graphe, int s1, int s2)
{
  t_list	*cur;

  cur = get_sommet(graphe, s1);
  rmv_adjacent(cur, s2);
  cur->nb_sommet_adjacent--;
  cur = get_sommet(graphe, s2);
  rmv_adjacent(cur, s1);
  cur->nb_sommet_adjacent--;
  return (0);
}

int	kill_the_way(t_graphe *graphe, t_way *to_kill, int start)
{
  int	i;
  t_list	*cur;

  cur = graphe->next;
  i = 1;
  while (i < to_kill->len)
    {
      kill_link(graphe, to_kill->chemin[i], to_kill->chemin[i - 1]);
      i++;
    }
  while (cur != NULL)
    {
      cur->fix = 0;
      cur->distance = INT_MAX;
      cur = cur->next;
    }
  if (get_sommet(graphe, start))
    {
      get_sommet(graphe, start)->fix = 0;
      get_sommet(graphe, start)->distance = 0;
    }
  return (0);

}

int	print_result(t_way *way)
{
  int	i;

  i = 0;
  if (way == NULL)
    return (0);
  printf("Nb_fourmie =\t%d\nLen = %d\n", way->nb_fourmies, way->len);
      printf("Result\t");
  while (i < way->len)
    {
      printf("%d-", way->chemin[i]);
      i++;
    }
  printf("\n");
  printf("len_th :\t%d\n", way->len_th);
  printf("len :\t%d\n\n", way->len);
  return (0);
}

int	fill_ways(t_way *ways, int nb_fourmis)
{
  t_way	*shortest_way;
  t_way	*cur;

  while (nb_fourmis)
    {
      cur = ways;
      shortest_way = cur;
      while (cur)
	{
	  if (cur->len_th < shortest_way->len_th)
	    shortest_way = cur;
	  cur = cur->next;
	}
      shortest_way->nb_fourmies++;
      shortest_way->len_th++;
      nb_fourmis--;
    }
  return (0);
}

int	print_all_result(t_way *ways)
{
  t_way	*cur;

  cur = ways;
  while (cur)
    {
      print_result(cur);
      cur = cur->next;
    }
  return (0);
}

t_fourmi	*add_fourmi(t_way *way, t_fourmi *fourmis, int *cpt)
{
  t_fourmi	*new;
  t_fourmi	*cur;

  new = malloc(sizeof (t_fourmi));
  new->numero_fourmi = cpt[0]++;
  new->posy = 0;
  new->chemin = way->chemin;
  new->len = way->len;
  new->next = NULL;
  if (fourmis == NULL)
    return (new);
  cur = fourmis;
  while (cur->next)
    cur = cur->next;
  cur->next = new;
  return (fourmis);
}

t_fourmi	*fill_wave(t_way *ways, t_fourmi *fourmis, int *cpt)
{
  t_way	*cur;

  cur = ways;
  while (cur)
    {
      if (cur->nb_fourmies > 0)
	{
	  fourmis = add_fourmi(cur, fourmis, cpt);
	  cur->nb_fourmies--;
	}
      cur = cur->next;
    }
  return (fourmis);
}

int	print_wave(t_fourmi *fourmis)
{
  t_fourmi	*cur;

  cur = fourmis;
  while (cur)
    {
      if (cur->posy <= cur->len)
	printf("P%d-%d ", cur->numero_fourmi, cur->chemin[cur->posy + 1]);
      cur->posy++;
      cur = cur->next;
    }
  return (0);
}

t_fourmi	*kill_fourmis(t_fourmi *fourmis)
{
  t_fourmi	*tmp;

  if (!fourmis)
    return (NULL);
  if (fourmis->posy >= fourmis->len - 1)
    {
      tmp = fourmis->next;
      free(fourmis);
      return (kill_fourmis(tmp));
    }
  else
    {
      fourmis->next = kill_fourmis(fourmis->next);
      return (fourmis);
    }
}

t_way	*get_ways(t_graphe *graphe, int start, int end, t_way *ways)
{
  while (dijkstra(graphe, start, end))
    {
      ways = get_solution(graphe, ways, end, start);
      kill_the_way(graphe, ways, start);
    }
  if (ways == NULL)
    {
      printf("Pas de chemin\n");
      exit(-1);
    }
  return (ways);
}

int	run_lem_in(t_way *ways)
{
  t_fourmi	*fourmis;
  int	*cpt;

  cpt = malloc(sizeof (int));
  cpt[0] = 1;
  fourmis = NULL;
  fourmis = fill_wave(ways, fourmis, cpt);
  while (fourmis)
    {
      print_wave(fourmis);
      printf("\n");
      fourmis = fill_wave(ways, fourmis, cpt);
      fourmis = kill_fourmis(fourmis);
    }

  return (0);
}

int		main(int argc, char **argv)
{
  t_graphe	*graphe;
  t_way		*ways;
  int		start;
  int		end;
  int		nb_fourmis;

  (void)argc;
  (void)argv;
  ways = NULL;
  nb_fourmis = 5;
  start = 9;
  end = 1;

  graphe = new_graphe();
  insert_arc(graphe, 9, 2);
  insert_arc(graphe, 9, 3);
  insert_arc(graphe, 2, 1);
  insert_arc(graphe, 1, 3);
  insert_arc(graphe, 2, 3);

  ways = get_ways(graphe, start, end, ways);
  fill_ways(ways, nb_fourmis);
  run_lem_in(ways);
  return (0);
}
