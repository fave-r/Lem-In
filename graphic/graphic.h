/*
** graphic.h for graphic in /home/thibaut.lopez/Lem-In/graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Thu Apr 24 15:45:29 2014 Thibaut Lopez
** Last update Sat Apr 26 02:53:31 2014 Thibaut Lopez
*/

#ifndef GRAPHIC_H
#define GRAPHIC_H
#define BPP(S)	(S)->format->BytesPerPixel

#include <math.h>
#include <SDL/SDL.h>

typedef struct	s_box
{
  SDL_Surface	*ret;
  double	error;
  double	x;
  double	y;
  double	cx;
  double	cy;
}		t_box;

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

#endif
