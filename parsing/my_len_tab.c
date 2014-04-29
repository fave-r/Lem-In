/*
** my_len_tab.c for my_len_tab in /home/alex-odet/work/Lem-In/parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Apr 18 14:55:14 2014 alex-odet
** Last update Mon Apr 28 17:49:39 2014 Alex
*/

#include "lem_in.h"

int	my_len_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] && tab != NULL)
    i++;
  return (i);
}
