/*
** get_ways_next.c for lem_in in /home/blackbird/work/Lem-In
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sun May  4 12:30:22 2014 romaric
** Last update Sun May  4 12:54:29 2014 romaric
*/

#include "lem_in.h"

void	kill_the_way_next(t_list **cur)
{
  (*cur)->fix = 0;
  (*cur)->distance = INT_MAX;
  (*cur) = (*cur)->next;
}
