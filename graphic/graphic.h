/*
** graphic.h for graphic in /home/thibaut.lopez/Lem-In/graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Thu Apr 24 15:45:29 2014 Thibaut Lopez
** Last update Wed Apr 30 16:29:31 2014 Thibaut Lopez
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
