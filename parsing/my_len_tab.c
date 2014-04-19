/*
** my_len_tab.c for my_len_tab in /home/alex-odet/work/Lem-In/parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Apr 18 14:55:14 2014 alex-odet
** Last update Fri Apr 18 14:57:37 2014 alex-odet
*/

#include "lem_in.h"

int	my_len_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
