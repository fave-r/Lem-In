/*
** my_list_size.c for my_list_size in /home/alex-odet/work/Lem-In/parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Sun Apr 20 17:18:27 2014 alex-odet
** Last update Sun Apr 20 17:19:20 2014 alex-odet
*/

#include "lem_in.h"

int	my_list_size(t_lem *list)
{
  int	i;

  i = 0;
  while (list)
    {
      i++;
      list = list->next;
    }
  return (i);
}
