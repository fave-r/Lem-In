/*
** list_fun.c for list_fun in /home/thibaut.lopez/Lem-In/graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Mon Apr 28 12:06:49 2014 Thibaut Lopez
** Last update Mon Apr 28 14:18:54 2014 Thibaut Lopez
*/

int	greater_x(t_lem *list)
{
  int    save;

  save = 0;
  while (list)
    {
      if (list->ptr.x > save)
	save = list->ptr.x;
      list = list->next;
    }
  save *= 10;
  return ((save >= 1000) ? save + 50 : 1000);
}


int	greater_y(t_lem *list)
{
  int    save;

  save = 0;
  while (list)
    {
      if (list->ptr.y > save)
	save = list->ptr.y;
      list = list->next;
    }
  save *= 10;
  return ((save >= 1000) ? save + 50 : 1000);
}

t_lem	*find_elem_in_list(char *name, t_lem *list)
{
  while (list)
    {
      if (strcmp(name, list->name) == 0)
	return (list);
      list = list->next;
    }
  return (NULL);
}
