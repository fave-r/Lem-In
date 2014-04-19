/*
** xfunction.c for xfunction in /home/alex-odet/work/Lem-In/parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Thu Apr 17 16:58:17 2014 alex-odet
** Last update Thu Apr 17 16:59:19 2014 alex-odet
*/

#include "lem_in.h"

void	*xmalloc(size_t n)
{
  void	*p;

  p = malloc(n);
  if (p == NULL)
    {
      my_putstr("Malloc failed.\n", 2);
      exit(EXIT_FAILURE);
    }
  return (p);
}
