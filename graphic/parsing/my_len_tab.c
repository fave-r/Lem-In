/*
** my_len_tab.c for my_len_tab in /home/alex-odet/work/Lem-In/parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Apr 18 14:55:14 2014 alex-odet
** Last update Wed Apr 30 16:49:20 2014 Thibaut Lopez
*/

#include "graphic.h"

int	my_len_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] && tab != NULL)
    i++;
  return (i);
}
