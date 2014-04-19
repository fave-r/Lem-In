/*
** error.c for error in /home/alex-odet/work/Lem-In/parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Apr 18 14:42:17 2014 alex-odet
** Last update Fri Apr 18 14:43:37 2014 alex-odet
*/

#include "lem_in.h"

void	bad_ants()
{
  fprintf(stderr, "Bad number of ants.\n");
  exit(EXIT_FAILURE);
}
