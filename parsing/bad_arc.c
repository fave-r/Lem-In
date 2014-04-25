/*
** bad_arc.c for bad_arc in /home/alex-odet/work/Lem-In/parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Apr 25 11:03:03 2014 alex-odet
** Last update Fri Apr 25 13:34:26 2014 alex-odet
*/

#include "lem_in.h"

void	bad_arc(char *room)
{
  printf("Undefined reference to the room: %s\n", room);
  exit(EXIT_FAILURE);
}
