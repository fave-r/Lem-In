/*
** main.c for lem_in in /home/thibaud/rendu/lem_in
** 
** Made by thixbaud
** Login   <thibaud@epitech.net>
** 
** Started on  Sat Apr 12 23:46:01 2014 thibaud
** Last update Wed Apr 16 02:50:08 2014 thibaud
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

/* void	my_xcopy(void src, ) */
/* { */

/* } */

t_noeud		*add_noeud(t_noeud *tab, int size, int s1, int s2)
{
  t_noeud	new;
  int		tmp;

  if (s1 > s2)
    {
      tmp = s1;
      s1 = s2;
      s2 = tmp;
    }
  new.sommet1 = s1;
  new.sommet2 = s2;
  if (tab == NULL)
    {
      tab = &new;
      return (tab);
    }
  tab = my_realloc(tab, size * sizeof (tab));
  tab[size - 1] = new;
  return (tab);
}

int	tab_swap(t_noeud *tab, int elem1, int elem2)
{
  t_noeud	tmp;

  tmp = tab[elem1];
  tab[elem1] = tab[elem2];
  tab[elem2] = tmp;
  return (0);
}

int	bubble_sort(t_noeud *tab, int size)
{
  int	i;
  int	action;

  action = 1;
  while (action == 1)
    {
      i = 0;
      action = 0;
      while (i < size - 1)
	{
	  if (tab[i].sommet1 > tab[i + 1].sommet1)
	    {
	      tab_swap(tab, i, i + 1);
	      action = 1;
	    }
	  if (tab[i].sommet1 == tab[i + 1].sommet1 &&
	      tab[i].sommet2 > tab[i + 1].sommet2)
	    {
	      tab_swap(tab, i, i + 1);
	      action = 1;
	    }
	  i++;
	}
    }
  return (0);
}

int	print_noeuds(t_noeud *tab, int size)
{
  int	i;

  if (tab == NULL)
    return (printf("Pas de noeud\n"));
  i = 0;
  while (i < size)
    {
      printf("%c-%c\n", tab[i].sommet1, tab[i].sommet2);
      i++;
    }
  return (0);
}

int		my_str_to_noeud(char *str, t_noeud *tab)
{
  int		s1;
  int		s2;
  int		size;

  s1 = 0;
  s2 = 0;
  size = 0;
  while (str && str[0] != '\0')
    {
      while (str[0] != '\0' && !my_isdigit(str[0]))
	str++;
      s1 = my_getnbr(str);
      while (str[0] != '\0' && my_isdigit(str[0]))
	str++;
      while (str[0] != '\0' && !my_isdigit(str[0]))
	str++;
      s2 = my_getnbr(str);
      while (str[0] != '\0' && my_isdigit(str[0]))
	str++;
      tab = add_noeud(tab, ++size, s1, s2);
    }
  bubble_sort(tab, size);
  print_noeuds(tab, size);
  tab = my_realloc(tab, sizeof (t_noeud) * size);
  return (size);
}

int	**build_arcs_tab(t_graphe *graphe, int start)
{
  int	**tab;
  int	size;
  int	i;
  int	j;
  t_list	*tmp;

  i = 0;
  size = get_max_sommet(graphe);
  printf("%d\n", size);
  tab = malloc(sizeof (int *) * size);
  while (i < size)
    {
      j = 0;
      tab[i] = malloc(sizeof (int) * size);
      while (j < size)
	{
	  tab[i][j] = arc_exist(graphe, i + 1, j + 1) ? 1 : 0;
	  j++;
	}
      i++;
    }
  tmp = get_sommet(graphe, start);
  tmp->distance = 0;
  return (tab);
}

int	print_arc_tab(int **arc_tab, int size)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (j < size)
    {
      i = 0;
      while (i < size)
	{
	  printf("%d ", arc_tab[j][i]);
	  i++;
	}
      printf("\n");
      j++;
    }
  return (0);
}

t_list		*fix_sommet(t_graphe *graphe)
{
  t_list	*cur;
  int		closest_sommet;
  int		closest_distance;

  closest_sommet = -1;
  closest_distance = INT_MAX;
  cur = graphe->next;
  while (cur != NULL)
    {
      if (cur->distance < closest_distance && cur->fix == 0)
	{
	  closest_distance = cur->distance;
	  closest_sommet = cur->numero_sommet;
	}
      cur = cur->next;
    }
  if (closest_distance != INT_MAX)
    get_sommet(graphe, closest_sommet)->fix = 1;
  return (get_sommet(graphe, closest_sommet));
}

int	get_tmp_distance(t_graphe *graphe, t_list *fix, int **arc_tab)
{
  int	i;

  i = 0;
  while (i < fix->nb_sommet_adjacent)
    {
      if (get_sommet(graphe, fix->adjacents[i])->distance >
	  (fix->distance + arc_tab[fix->numero_sommet - 1]
	   [fix->adjacents[i] - 1]))
	{
	  get_sommet(graphe, fix->adjacents[i])->distance =
	    fix->distance + arc_tab[fix->numero_sommet - 1]
	    [fix->adjacents[i] - 1];
	  get_sommet(graphe, fix->adjacents[i])->last = fix->numero_sommet;
	}
      i++;
    }
  return (0);
}

int	print_dijsktra(t_graphe *graphe, int end, int start)
{
  t_list	*cur;

  cur = get_sommet(graphe, end);
  while (cur->numero_sommet != start)
    {
      printf("%d-%d\n", cur->numero_sommet, cur->last);
      cur = get_sommet(graphe, cur->last);
    }
  return (0);
}

int	dijkstra(t_graphe *graphe, int start, int end)
{
  int		**arc_tab;
  t_list	*tmp;


  if (get_sommet(graphe, start) == NULL || get_sommet(graphe, end) == NULL)
    exit(-1);
  arc_tab = build_arcs_tab(graphe, start);  
  tmp = fix_sommet(graphe);
  while (get_sommet(graphe, end)->fix == 0)
    {
      get_tmp_distance(graphe, tmp, arc_tab);
      tmp = fix_sommet(graphe);
    }
  return (0);
}

int		main(int argc, char **argv)
{
  //char		*str;
  t_graphe	*graphe;

  (void)argc;
  (void)argv;
  //str = argv[1];


  graphe = new_graphe();
  insert_arc(graphe, 1, 2);
  insert_arc(graphe, 1, 3);
  insert_arc(graphe, 1, 4);
  insert_arc(graphe, 2, 5);
  //insert_arc(graphe, 3, 6);
  insert_arc(graphe, 4, 6);
  insert_arc(graphe, 6, 7);


  dijkstra(graphe, 1, 7);
  print_dijsktra(graphe, 7, 1);
  return (0);
}
