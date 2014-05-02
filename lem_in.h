/*
** lem_in.h for lem_in in /home/thibaud/rendu/lem_in
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Sat Apr 12 23:41:54 2014 thibaud
** Last update Fri May  2 16:43:47 2014 romaric
*/

#ifndef LEM_IN_
#define LEM_IN_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

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
  int			x;
  int			y;
}			t_coor;

typedef struct		s_lem
{
  int			is_start;
  char			*name;
  t_coor		ptr;
  struct s_lem		*next;
}			t_lem;

typedef struct		s_arc
{
  char			*first;
  int			first_room;
  char			*second;
  int			second_room;
  struct s_arc		*next;
}			t_arc;

typedef struct		s_ant
{
  char			*ant_name;
  char			*whereis;
}			t_ant;

typedef struct		s_all
{
  int			ants;
  char			**map;
  t_lem			*room;
  t_arc			*arc;
  t_ant			*move;
}			t_all;

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
t_way           *get_solution(t_graphe *graphe
			      , t_way *list_chemins, int end, int start);
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
int		print_arc_tab(int **, int);
int		my_isdigit(char);

void		bad_ants();
void		no_start();
void		no_end();
void		bad_coor();
void		bad_len();
int		my_len_tab(char **tab);
t_lem		*new_node(char *name, int x, int y);
t_lem		*my_put_in_lem_list(t_lem *list, char *name, int x, int y);
t_lem		*my_put_start(t_lem *list, char *name, int x, int y);
t_lem		*my_put_end(t_lem *list, char *name, int x, int y);
int		parse_ants(char *tab);
t_lem		*parse_room(char **tab, int *i);
t_lem		*loop_parse(t_lem **list, char *tab);
void		check_tab(char **tab);
void		*xmalloc(size_t n);
int		my_list_size(t_lem *list);
int		strlen_word(const char *str, char *sep);
int		lentab(char *str, char *sep);
char		**my_str_to_wordtab(char *str, char *sep);
t_lem		*parse_room_start(int *bool_start, t_lem *list, char *map);
t_lem		*parse_room_other(t_lem *list, char *tmp);
t_lem		*parse_room_end(int *bool_end, t_lem *list, char *tmp);
int		my_strchr(char src, char *dest);
char		**init_parse();
void		sfree(char **tab);
char		*my_strdup(char *src);
int		my_strslen(char **tab);
char		**my_strscat(char **tab, char *str);
void		bad_arc(char *room);
t_arc		*new_arc_node(char *name, char *second);
t_arc		*my_put_in_arc_list(t_arc *list, char *first, char *second);
t_arc		*parse_arc(t_lem *list, int *i, char **map);
void		check_len_tab(char **tab, char *arc);
t_arc		*is_valid(char *first, char *second, t_lem *list, t_arc *arc);
void		my_show_arc(t_arc *list);
t_lem		*fill_list_num(t_lem *list);
t_arc		*arc_num(t_arc *arc, t_lem *list);
void		no_map();
void		no_arc();
void		algo(t_arc *arc, t_lem *list, int ants);
void		check_bool(int *bool_start, int *bool_end);
void		my_show_map(char **map);
void		free_arc(t_arc *arc);
void		free_list(t_lem *list);
t_all		*parse();
void		parse_room_next(int *bool_start, int *bool_end, t_lem **list);

#endif
