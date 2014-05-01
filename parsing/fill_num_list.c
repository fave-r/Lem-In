/*
** fill_num_list.c for fill_num_list in /Users/Alex/work/Lem-In/parsing
** 
** Made by Alex
** Login   <Alex@epitech.net>
** 
** Started on  Mon Apr 28 14:42:06 2014 Alex
** Last update Thu May  1 14:04:53 2014 Alex
*/

#include "lem_in.h"

t_lem	*fill_list_num(t_lem *list)
{
  t_lem	*tmp;
  int	i;
  int	len;

  i = 2;
  tmp = list;
  len = my_list_size(list);
  while (tmp)
    {
      if (tmp->is_start == 1)
	tmp->ptr.num = 1;
      if (tmp->is_start == 0)
	{
	  tmp->ptr.num = i;
	  i++;
	}
      if (tmp->is_start == 2)
	tmp->ptr.num = len;
      tmp = tmp->next;
    }
  return (list);
}
