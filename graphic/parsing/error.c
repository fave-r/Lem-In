/*
** error.c for lem-in in /home/blackbird/work/Lem-In/parsing
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sat Apr 19 14:22:42 2014 romaric
** Last update Wed Apr 30 16:48:10 2014 Thibaut Lopez
*/

#include "graphic.h"

void	bad_ants()
{
  fprintf(stderr, "Bad number of ants.\n");
  exit(EXIT_FAILURE);
}

void    no_start()
{
  printf("Syntax error : No entry in the map.\n");
  exit(EXIT_FAILURE);
}

void    no_end()
{
  printf("Syntax error : No end in the map.\n");
  exit(EXIT_FAILURE);
}

void    bad_coor()
{
  printf("Syntax error in coor values.\n");
  exit(EXIT_FAILURE);
}

void    bad_len()
{
  printf("Syntax error in room description.\n");
  exit(EXIT_FAILURE);
}
