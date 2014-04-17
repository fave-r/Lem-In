/*
** lem_in.h for lem_in in /home/thibaud/rendu/lem_in
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Sat Apr 12 23:41:54 2014 thibaud
** Last update Thu Apr 17 06:53:26 2014 thibaud
*/

#ifndef LEM_IN_
#define LEM_IN_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct		s_list
{
  int			numero_sommet;
  int			nb_sommet_adjacent;
  int			*adjacents;
  int			fix;
  int			distance;
  int			last;
  struct s_list		*next;
}			t_list;

typedef struct		s_graphe
{
  int			nb_sommet;
  int			nb_arcs;
  t_list		*next;
}			t_graphe;

typedef struct		s_file
{
  int			elem;
  struct s_file		*next;
}			t_file;

typedef struct		s_noeud
{
  int			sommet1;
  int			sommet2;
}			t_noeud;

typedef struct		s_way
{
  int			posy;
  int			numero_fourmie;
  int			len;
  int			*chemin;
  struct s_way		*next;
}			t_way;

t_graphe        *new_graphe(void);
int		add_sommet(t_graphe *graphe, int new_nb);
int		sommet_exist(t_graphe *graphe, int nb);
void		*my_realloc(void *source, int size);
int		add_arc(t_graphe *graphe, int sommet1, int sommet2);
int		arc_exist(t_graphe *graphe, int sommet, int adjacent);
int		insert_arc(t_graphe *graphe, int sommet1, int sommet2);

int     dijkstra(t_graphe *graphe, int start, int end);
int     get_tmp_distance(t_graphe *graphe, t_list *fix, int **arc_tab);
t_list          *fix_sommet(t_graphe *graphe);
int     **build_arcs_tab(t_graphe *graphe, int start);
t_list          *get_sommet(t_graphe *graphe, int nb);
int             get_max_sommet(t_graphe *graphe);



int		print_graphe(t_graphe *graphe);
int     print_dijsktra(t_graphe *graphe, int end, int start);
int	my_isdigit(char);

#endif
