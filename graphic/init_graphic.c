/*
** init_graphic.c for init_graphic in /home/thibaut.lopez/Corewar/Corewar/vm/Graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 19 09:16:50 2014 Thibaut Lopez
** Last update Mon Apr 28 14:19:18 2014 Thibaut Lopez
*/

#include "graphic.h"

int	my_pause(SDL_Surface *screen, SDL_Surface *arena, int x, int y, int posx, int posy)
{
  int		wait;
  SDL_Event	event;
  SDL_Rect	position;

  wait = 0;
  position.x = 0;
  position.y = 0;
  while (wait == 0)
    {
      SDL_WaitEvent(&event);
      if (event.key.keysym.sym == SDLK_ESCAPE)
	return (1);
      else if (event.key.keysym.sym == SDLK_SPACE &&
	       event.type == SDL_KEYDOWN)
	wait = 1;
      else if (event.key.keysym.sym == SDLK_DOWN && posy + y - 10 >= 1000)
	{
	  y -= 10;
	  position.x = x;
	  position.y = y;
	  SDL_BlitSurface(arena, NULL, screen, &position);
	  SDL_Flip(screen);
	}
      else if (event.key.keysym.sym == SDLK_UP && y + 10 <= 0)
	{
	  y += 10;
	  position.x = x;
	  position.y = y;
	  SDL_BlitSurface(arena, NULL, screen, &position);
	  SDL_Flip(screen);
	}
      else if (event.key.keysym.sym == SDLK_RIGHT && posx + x - 10 >= 1000)
	{
	  x -= 10;
	  position.x = x;
	  position.y = y;
	  SDL_BlitSurface(arena, NULL, screen, &position);
	  SDL_Flip(screen);
	}
      else if (event.key.keysym.sym == SDLK_LEFT && x + 10 <= 0)
	{
	  x += 10;
	  position.x = x;
	  position.y = y;
	  SDL_BlitSurface(arena, NULL, screen, &position);
	  SDL_Flip(screen);
	}
    }
  return (0);
}

void	fill_arena(SDL_Surface *arena, int x, int y)
{
  SDL_Rect	position;
  SDL_Surface	*image;

  image = SDL_LoadBMP("dirt_texture.bmp"); 
  if (image == NULL)
    {
      SDL_FillRect(arena, NULL, SDL_MapRGB(arena->format, 150, 150, 150));
      return;
    }
  position.x = 0;
  position.y = 0;
  SDL_BlitSurface(image, NULL, arena, &position);
  if (position.h != 50 || position.w != 50)
    SDL_FillRect(arena, NULL, SDL_MapRGB(arena->format, 150, 150, 150));
  while (position.h == 50 && position.w == 50 && position.y < y)
    {
      SDL_BlitSurface(image, NULL, arena, &position);
      position.x += 50;
      if (position.x == x)
	{
	  position.x = 0;
	  position.y += 50;
	}
    }
  SDL_FreeSurface(image);
}

int	init_graphic()
{
  SDL_Surface	*screen;
  SDL_Surface	*arena;
  SDL_Rect	a;
  SDL_Rect	b;
  SDL_Rect	position;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (1);
  if ((screen = SDL_SetVideoMode(1000, 1000, 32, SDL_SWSURFACE)) == NULL)
    return (1);
  SDL_WM_SetCaption("Lem-In", NULL);
  arena = SDL_CreateRGBSurface(SDL_HWSURFACE, /*1000*/1500, 1000, 32, 0, 0, 0, 0);
  fill_arena(arena, /*1000*/1500, 1000);
  a.x = 1450;
  //a.x = 950;
  a.y = 150;
  b.x = 800;
  b.y = 150;
  draw_tubes(&a, &b, arena);
  b.x = 800;
  b.y = 350;
  draw_tubes(&a, &b, arena);
  a.x = 800;
  a.y = 350;
  b.x = 800;
  b.y = 250;
  draw_tubes(&a, &b, arena);
  b.x = 450;
  b.y = 150;
  draw_tubes(&a, &b, arena);
  b.x = 200;
  b.y = 400;
  draw_tubes(&a, &b, arena);
  a.x = 800;
  a.y = 150;
  b.x = 800;
  b.y = 250;
  draw_tubes(&a, &b, arena);
  b.x = 450;
  b.y = 150;
  draw_tubes(&a, &b, arena);
  a.x = 800;
  a.y = 250;
  b.x = 450;
  b.y = 250;
  draw_tubes(&a, &b, arena);
  a.x = 450;
  a.y = 150;
  b.x = 50;
  b.y = 250;
  draw_tubes(&a, &b, arena);
  a.x = 50;
  a.y = 250;
  b.x = 200;
  b.y = 400;
  draw_tubes(&a, &b, arena);
  b.x = 450;
  b.y = 250;
  draw_tubes(&a, &b, arena);
  //draw_circle(0xFF0000, arena, 950, 150);
  draw_circle(0xFF0000, arena, 1450, 150);
  draw_circle(0xFFFFFF, arena, 800, 350);
  draw_circle(0xFFFFFF, arena, 800, 150);
  draw_circle(0xFFFFFF, arena, 800, 250);
  draw_circle(0xFFFFFF, arena, 450, 150);
  draw_circle(0xFFFFFF, arena, 50, 250);
  draw_circle(0xFFFFFF, arena, 200, 400);
  draw_circle(0x00FF00, arena, 450, 250);
  position.x = 0;
  position.y = 0;
  SDL_BlitSurface(arena, NULL, screen, &position);
  SDL_Flip(screen);
  my_pause(screen, arena, 0, 0, /*1000*/1500, 1000);
  return (0);
}

int	main()
{
  init_graphic();
  return (0);
}
