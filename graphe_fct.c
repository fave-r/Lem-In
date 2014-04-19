/*
** graphe.fct.c for lem_in in /home/thibaud/rendu/lem_in
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Sun Apr 13 03:01:17 2014 thibaud
** Last update Sat Apr 19 23:47:21 2014 thibaud
*/

#include "lem_in.h"

int		add_arc(t_graphe *graphe, int sommet1, int sommet2)
{
  t_list        *cur;

  cur = graphe->next;
  while (cur != NULL)
    {
      if (cur->numero_sommet == sommet1)
        {
          cur->nb_sommet_adjacent++;
          cur->adjacents = realloc(cur->adjacents, sizeof(int)
				   * cur->nb_sommet_adjacent);
          cur->adjacents = realloc(cur->adjacents, sizeof(int)
				   * cur->nb_sommet_adjacent);
          cur->adjacents[cur->nb_sommet_adjacent - 1] = sommet2;
        }
      cur = cur->next;
    }
  return (0);
}

int		arc_exist(t_graphe *graphe, int sommet, int adjacent)
{
  t_list        *cur;
  int		i;

  i = 0;
  cur = graphe->next;
  while (cur != NULL)
    {
      if (cur->numero_sommet == sommet)
        {
          while (i < cur->nb_sommet_adjacent)
            {
              if (cur->adjacents[i] == adjacent)
                return (1);
              i++;
            }
	}
      cur = cur->next;
    }
  return (0);
}

int		insert_arc(t_graphe *graphe, int sommet1, int sommet2)
{
  if (!sommet_exist(graphe, sommet1))
    add_sommet(graphe, sommet1);
  if (!sommet_exist(graphe, sommet2))
    add_sommet(graphe, sommet2);
  if (!arc_exist(graphe, sommet1, sommet2)
      || !arc_exist(graphe, sommet2, sommet1))
    graphe->nb_arcs++;
  if (!arc_exist(graphe, sommet1, sommet2))
    add_arc(graphe, sommet1, sommet2);
  if (!arc_exist(graphe, sommet2, sommet1))
    add_arc(graphe, sommet2, sommet1);
  return (0);
}

int		print_graphe(t_graphe *graphe)
{
  t_list        *list;
  int		i;

  printf("Nombre de sommets = %d\nNombre d'arcs = %d\n\n"
	 , graphe->nb_sommet, graphe->nb_arcs);
  i = 0;
  list = graphe->next;
  while (list != NULL)
    {
      printf("\nSommet\tn°%d\nNombre de sommet adjacent\t%d\n"
	     , list->numero_sommet, list->nb_sommet_adjacent);
      if (list->nb_sommet_adjacent != 0)
        printf("Sommets adjacents :\t");
      while (i < list->nb_sommet_adjacent)
        {
          printf("%d ", list->adjacents[i]);
          i++;
        }
      printf("\nFix =\t%d", list->fix);
      printf("\nDistance =\t%d\n", list->distance);
      printf("\n");
      i = 0;
      list = list->next;
    }
  return (0);
}
