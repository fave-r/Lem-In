/*
** graphic.h for graphic in /home/thibaut.lopez/Lem-In/graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Thu Apr 24 15:45:29 2014 Thibaut Lopez
** Last update Wed Apr 30 16:53:09 2014 Thibaut Lopez
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

typedef struct		s_ant
{
  char			*ant_name;
  char			*whereis;
}			t_ant;

typedef struct		s_all
{
  t_lem			*room;
  t_arc			*arc;
  t_ant			*move;
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
t_all		*parse();


void	put_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
void	draw_circle(Uint32 pixel, SDL_Surface *arena, int x, int y);
void	draw_tubes(SDL_Rect *f_box, SDL_Rect *s_box, SDL_Surface *arena);
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

#endif
