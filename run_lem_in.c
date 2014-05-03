/*
** run_lem_in.c for lem_in in /home/thibaud/rendu/Lem-In
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Sat Apr 19 23:20:28 2014 thibaud
** Last update Sat May  3 03:47:39 2014 thibaud
*/

#include "lem_in.h"

int             run_lem_in(t_way *ways, t_lem *list)
{
  t_fourmi      *fourmis;
  int           *cpt;

  cpt = malloc(sizeof (int));
  cpt[0] = 1;
  fourmis = NULL;
  fourmis = fill_wave(ways, fourmis, cpt);
  while (fourmis)
    {
      print_wave(fourmis, list);
      printf("\n");
      fourmis = fill_wave(ways, fourmis, cpt);
      fourmis = kill_fourmis(fourmis);
    }
  free(cpt);
  return (0);
}

t_fourmi        *kill_fourmis(t_fourmi *fourmis)
{
  t_fourmi      *tmp;

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

t_fourmi        *fill_wave(t_way *ways, t_fourmi *fourmis, int *cpt)
{
  t_way         *cur;

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

t_fourmi        *add_fourmi(t_way *way, t_fourmi *fourmis, int *cpt)
{
  t_fourmi      *new;
  t_fourmi      *cur;

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

int             fill_ways(t_way *ways, int nb_fourmis)
{
  t_way         *shortest_way;
  t_way         *cur;

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
