/*
** parse.c for parse in /Users/Alex/work/Lem-In
** 
** Made by Alex
** Login   <Alex@epitech.net>
** 
** Started on  Wed Apr 30 16:09:14 2014 Alex
** Last update Thu May  1 16:31:33 2014 Alex
*/

#include "graphic.h"

void	parse(t_all *list)
{
  int	i;

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
  list->ant = ants(list->ants, list->room);
}

t_mov	*parse_move(char **map, int *i)
{
  t_mov	*ants;
  char	**tmp_tab;

  ants = NULL;
  while (map[*i] != NULL)
    {
      tmp_tab = my_str_to_wordtab(map[*i], " \t");
      ants = fill_ants(ants, tmp_tab);
      *i = *i + 1;
    }
  return (ants);
}

t_mov	*fill_ants(t_mov *ant, char **tab)
{
  int	i;
  char	**move_tab;

  i = 0;
  while (tab[i])
    {
      move_tab = my_str_to_wordtab(tab[i], "-");
      ant = my_put_ant(ant, move_tab[0], move_tab[1]);
      i++;
    }
  return (ant);
}

t_mov	*new_ant_node(char *ant_name, char *room)
{
  t_mov	*new;

  new = malloc(sizeof(t_mov));
  new->ant_num = atoi(ant_name + 1);
  new->whereis = strdup(room);
  new->next = NULL;
  return (new);
}

t_mov	*my_put_ant(t_mov *ptr, char *ant_name, char *room)
{
  t_mov	*tmp;

  if (ptr == NULL)
    return (new_ant_node(ant_name, room));
  tmp = ptr;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_ant_node(ant_name, room);
  return (ptr);
}
