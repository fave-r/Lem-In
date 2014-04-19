/*
** graph_fct_next.c for lem_in in /home/blackbird/work/Lem-In
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Thu Apr 17 16:38:07 2014 romaric
** Last update Sat Apr 19 23:10:24 2014 thibaud
*/

#include "lem_in.h"

t_graphe	*new_graphe(void)
{
  t_graphe	*new;

  if ((new = malloc(sizeof(t_graphe))) == NULL)
    exit(0);
  new->nb_sommet = 0;
  new->next = NULL;
  return (new);
}

int		add_sommet(t_graphe *graphe, int new_nb)
{
  t_list      	*cur;
  t_list       	*new_sommet;

  new_sommet = malloc(sizeof(t_list));
  cur = graphe->next;
  while (cur != NULL && cur->next != NULL)
    cur = cur->next;
  new_sommet->numero_sommet = new_nb;
  new_sommet->nb_sommet_adjacent = 0;
  new_sommet->adjacents = NULL;
  new_sommet->next = NULL;
  new_sommet->fix = 0;
  new_sommet->distance = INT_MAX;
  new_sommet->last = -1;
  if (cur == NULL)
    graphe->next  = new_sommet;
  else
    cur->next = new_sommet;
  graphe->nb_sommet++;
  return (0);
}

int		sommet_exist(t_graphe *graphe, int nb)
{
  t_list	*cur;

  cur = graphe->next;
  while (cur)
    {
      if (cur->numero_sommet == nb)
        return (1);
      cur = cur->next;
    }
  return (0);
}
