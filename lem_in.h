/*
** lem_in.h for lem_in in /home/thibaud/rendu/lem_in
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Sat Apr 12 23:41:54 2014 thibaud
** Last update Sat Apr 19 23:57:41 2014 thibaud
*/

#ifndef LEM_IN_
#define LEM_IN_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define BUFF_SIZE 4096

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

typedef struct		s_fourmi
{
  int			numero_fourmi;
  int			posy;
  int			*chemin;
  int			len;
  struct s_fourmi	*next;
}			t_fourmi;

typedef struct		s_way
{
  int			nb_fourmies;
  int			len;
  int			len_th;
  int			*chemin;
  struct s_way		*next;
}			t_way;

typedef struct		s_coor
{
  int			num;
  char			*name;
  int			x;
  int			y;
}			t_coor;

typedef struct		s_lem
{
  int			ants;
  t_coor		ptr;
  struct s_lem		*next;
}			t_lem;

typedef struct		s_get
{
  char			*s;
  int			c;
  int			l;
}			t_get;

typedef struct		s_pars
{
  int			ants;
  char			**tmp2;
  char			*tmp;
  int			i;
  int			line;
}			t_pars;

t_graphe	*new_graphe(void);
int		add_sommet(t_graphe *graphe, int new_nb);
int		sommet_exist(t_graphe *graphe, int nb);
void		*my_realloc(void *source, int size);
int		add_arc(t_graphe *graphe, int sommet1, int sommet2);
int		arc_exist(t_graphe *graphe, int sommet, int adjacent);
int		insert_arc(t_graphe *graphe, int sommet1, int sommet2);
int		dijkstra(t_graphe *graphe, int start, int end);
int		get_tmp_distance(t_graphe *graphe, t_list *fix, int **arc_tab);
t_list          *fix_sommet(t_graphe *graphe);
int		**build_arcs_tab(t_graphe *graphe, int start);
t_list          *get_sommet(t_graphe *graphe, int nb);
int             get_max_sommet(t_graphe *graphe);
t_way           *get_ways(t_graphe *graphe, int start, int end, t_way *ways);
t_way           *get_solution(t_graphe *graphe, t_way *list_chemins, int end, int start);
int             kill_the_way(t_graphe *graphe, t_way *to_kill, int start);
int             kill_link(t_graphe *graphe, int s1, int s2);
int             fill_ways(t_way *ways, int nb_fourmis);
t_fourmi        *add_fourmi(t_way *way, t_fourmi *fourmis, int *cpt);
t_fourmi        *fill_wave(t_way *ways, t_fourmi *fourmis, int *cpt);
t_fourmi        *kill_fourmis(t_fourmi *fourmis);
int             run_lem_in(t_way *ways);
int		my_rev_tab(int *tab, int len);
int		rmv_adjacent(t_list *cur, int s2);
int		my_len_tab(char **tab);

int             free_arc_tab(int **arc_tab, int size);
int		free_graphe(t_graphe *graphe);
int		free_ways(t_way *ways);

int		print_graphe(t_graphe *graphe);
int		print_dijsktra(t_graphe *graphe, int end, int start);
int             print_result(t_way *way);
int             print_all_result(t_way *ways);
int             print_wave(t_fourmi *fourmis);
int		my_isdigit(char);


#endif
