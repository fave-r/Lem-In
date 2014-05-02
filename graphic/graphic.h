/*
** graphic.h for graphic in /home/thibaut.lopez/Lem-In/graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Thu Apr 24 15:45:29 2014 Thibaut Lopez
** Last update Fri May  2 15:33:08 2014 Alex
*/

#ifndef GRAPHIC_H
#define GRAPHIC_H
#define BPP(S)	(S)->format->BytesPerPixel

#include <math.h>
#include <SDL/SDL.h>
#include <unistd.h>

typedef struct	s_box
{
  SDL_Surface	*ret;
  double	error;
  double	x;
  double	y;
  double	cx;
  double	cy;
}		t_box;

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

typedef struct		s_mov
{
  int			ant_num;
  char			*whereis;
  struct s_mov		*next;
}			t_mov;

typedef struct		s_round
{
  t_mov			*ptr;
  struct s_round       	*next;
}			t_round;

typedef struct		s_ant
{
  int			num;
  int			ant_x;
  int			ant_y;
  struct s_ant		*next;
}			t_ant;

typedef struct		s_all
{
  int			ants;
  char			**map;
  t_lem			*room;
  t_arc			*arc;
  t_round      		*move;
  t_ant			*ant;
}			t_all;

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
void		check_bool(int *bool_start, int *bool_end);
void		free_arc(t_arc *arc);
void		free_list(t_lem *list);
void		parse(t_all *list);
t_round		*parse_move(char **map, int *i);
t_ant		*ants(int nb_ants, t_lem *room);
t_ant		*fill_ant_num(t_ant *ptr, int nb, t_lem *room);
t_ant		*node(int nb, int x, int y);
t_ant		*create_list(t_ant *ptr, int nb, int x, int y);
t_round		*round_node(t_mov *ptr);
t_round		*round_list(t_round *ptr, t_mov *list);
t_mov		*mov_node(char *name, char *room);
t_mov		*my_put_mov(t_mov *ptr, char *name, char *room);

void	put_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
Uint32	get_pixel(SDL_Surface *surface, int x, int y);
void	draw_circle(Uint32 pixel, SDL_Surface *arena, t_coor *pos, int scale);
void	draw_tubes(SDL_Rect *f_box, SDL_Rect *s_box, SDL_Surface *arena, int scale);
void	draw_line(SDL_Rect *a, SDL_Rect *b, SDL_Surface *arena);
void	flat1(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b);
void	flat2(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b);
void	vert1(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b);
void	vert2(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b);
void	quarter1(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b, int *delta);
void	quarter2(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b, int *delta);
void	quarter3(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b, int *delta);
void	quarter4(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b, int *delta);
void	quarter5(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b, int *delta);
void	quarter6(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b, int *delta);
void	quarter7(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b, int *delta);
void	quarter8(SDL_Surface *arena, SDL_Rect *a, SDL_Rect *b, int *delta);
int	operate_event(SDL_Surface *screen, SDL_Surface *arena, SDL_Rect *pos, SDL_Rect *dim);
int	greater_x(t_lem *list, int *scale);
int	greater_y(t_lem *list, int *scale);
t_lem	*find_elem_in_list(char *name, t_lem *list);
void	init_tubes(t_arc *arc, t_lem *room, SDL_Surface *arena, int scale);
void	init_circle(t_lem *room, SDL_Surface *arena, int scale);

#endif
