/*
** parse.c for parse in /Users/Alex/work/Lem-In
**
** Made by Alex
** Login   <Alex@epitech.net>
**
** Started on  Wed Apr 30 16:09:14 2014 Alex
** Last update Fri May  2 15:34:12 2014 Alex
*/

#include "graphic.h"

void	       show_ant(t_mov *list)
{
  while (list)
    {
      printf("ant : %d\t is room : %s\n", list->ant_num, list->whereis);
      list = list->next;
    }
}

void		show_round(t_round *list)
{
  int	i;

  i = 0;
  while (list)
    {
      printf("au tour : %d\t", i);
      show_ant(list->ptr);
      list = list->next;
      i++;
    }
}

void		parse(t_all *list)
{
  int		i;

  i = 1;
  list->map = init_parse();
  if (list->map == NULL)
    no_map();
  list->ants = parse_ants(list->map[0]);
  list->room = parse_room(list->map, &i);
  list->room = fill_list_num(list->room);
  list->arc = parse_arc(list->room, &i, list->map);
  if (list->arc == NULL)
    no_arc();
  list->arc = arc_num(list->arc, list->room);
  list->move = parse_move(list->map, &i);
  show_round(list->move);
  list->ant = ants(list->ants, list->room);
}

t_round		*parse_move(char **map, int *i)
{
  char			**tab;
  int			tmp;
  t_round		*list;
  char			**second;

  list = NULL;
  list->ptr = NULL;
  while (map[*i])
    {
      tmp = 0;
      tab = my_str_to_wordtab(map[*i], " ");
      while (tab[tmp])
	{
	  second = my_str_to_wordtab(tab[tmp], "-");
	  list->ptr = my_put_mov(list->ptr, second[0], second[1]);
	  tmp++;
	}
      list = round_list(list, list->ptr);
      sfree(second);
      *i = *i + 1;
    }
  return (list);
}

t_round		*round_node(t_mov *ptr)
{
  t_round	*new;

  new = xmalloc(sizeof(t_round));
  new->ptr = ptr;
  new->next = NULL;
  return (new);
}

t_mov		*mov_node(char *name, char *room)
{
  t_mov		*new;

  new = xmalloc(sizeof(t_mov));
  new->ant_num = atoi(name + 1);
  new->whereis = strdup(room);
  new->next = NULL;
  return (new);
}

t_mov		*my_put_mov(t_mov *ptr, char *name, char *room)
{
  t_mov		*tmp;

  if (ptr == NULL)
    return (mov_node(name, room));
  tmp = ptr;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = mov_node(name, room);
  return (ptr);
}

t_round		*round_list(t_round *ptr, t_mov *list)
{
  t_round		*tmp;

  if (ptr == NULL)
    return (round_node(list));
  tmp = ptr;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = round_node(list);
  return (ptr);
}
