/*
** xfunction.c for xfunction in /home/alex-odet/work/Lem-In/parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Thu Apr 17 16:58:17 2014 alex-odet
** Last update Wed Apr 30 16:51:04 2014 Thibaut Lopez
*/

#include "graphic.h"

void	*xmalloc(size_t n)
{
  void	*p;

  p = malloc(n);
  if (p == NULL)
    {
      fprintf(stderr, "Malloc failed.\n");
      exit(EXIT_FAILURE);
    }
  return (p);
}
