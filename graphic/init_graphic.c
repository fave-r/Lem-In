/*
** init_graphic.c for init_graphic in /home/thibaut.lopez/Corewar/Corewar/vm/Graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 19 09:16:50 2014 Thibaut Lopez
** Last update Thu May  1 12:29:19 2014 Thibaut Lopez
*/

#include "graphic.h"

void	fill_arena(SDL_Surface *arena, int x, int y)
{
  SDL_Rect	position;
  SDL_Surface	*image;

  image = SDL_LoadBMP("tools/dirt_texture.bmp");
  if (image == NULL)
    {
      SDL_FillRect(arena, NULL, SDL_MapRGB(arena->format, 150, 150, 150));
      return;
    }
  position.x = 0;
  position.y = 0;
  if (image->w != 50 || image->h != 50)
    SDL_FillRect(arena, NULL, SDL_MapRGB(arena->format, 150, 150, 150));
  while (position.y < y)
    {
      SDL_BlitSurface(image, NULL, arena, &position);
      position.x += 50;
      if (position.x >= x)
	{
	  position.x = 0;
	  position.y += 50;
	}
    }
  SDL_FreeSurface(image);
}

int	init_graphic(t_all *all, SDL_Rect *pos, int scale)
{
  SDL_Surface	*screen;
  SDL_Surface	*arena;
  SDL_Rect	init;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (1);
  if ((screen = SDL_SetVideoMode(1000, 1000, 32, SDL_SWSURFACE)) == NULL)
    return (1);
  SDL_WM_SetCaption("Lem-In", NULL);
  arena = SDL_CreateRGBSurface(SDL_SWSURFACE, pos->x, pos->y, 32, 0, 0, 0, 0);
  if (arena == NULL)
    exit(printf("%s\n", SDL_GetError()));
  fill_arena(arena, pos->x, pos->y);
  init_tubes(all->arc, all->room, arena, scale);
  init_circle(all->room, arena, scale);
  init.x = 0;
  init.y = 0;
  SDL_BlitSurface(arena, NULL, screen, &init);
  SDL_Flip(screen);
  if (operate_event(screen, arena, &init, pos) == 1)
    SDL_FreeSurface(arena);
  return (0);
}

int	main()
{
  int		scale;
  SDL_Rect	pos;
  t_all		all;

  scale = 0;
  parse(&all);
  pos.x = greater_x(all.room, &scale);
  if (pos.x == -1)
    exit(printf("Width or height is too large\n"));
  pos.y = greater_y(all.room, &scale);
  if (pos.y == -1)
    exit(printf("Width or height is too large\n"));
  init_graphic(&all, &pos, scale);
  free_list(all.room);
  free_arc(all.arc);
  return (0);
}
