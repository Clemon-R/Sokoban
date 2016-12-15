/*
** map.c for exam in /home/raphael.goulmot/rendu/PSU_2016_my_sokoban
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Dec 13 10:45:59 2016 Raphaël Goulmot
** Last update Thu Dec 15 13:37:18 2016 Raphaël Goulmot
*/

#include "map.h"
#include "utils.h"
#include "sokoban.h"
#include "trigger.h"
#include <ncurses/curses.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

int	my_getpos_player(char *str)
{
  int	i;

  i = 0;
  while (str[i++])
    if (str[i - 1] == 'P')
      return (i - 1);
  return (-1);
}

char    check_map(t_map *map)
{
  int   i;
  char	*str;

  i = 0;
  str = map->data;
  while (str[i])
    {
      if (str[i] != '#' && str[i] != 'P' && str[i] != '\n'
	  && str[i] != 'O' && str[i] != ' ' && str[i] != 'X')
	return (0);
      i++;
    }
  if (map->height > LINES || map->width > COLS)
    return (0);
  return (1);
}

int     count_lines(char *str)
{
  int   i;
  int   len;

  i = 0;
  len = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	len++;
      i++;
    }
  return (len);
}

int     count_size(char *str)
{
  int   i;

  i = 0;
  while (str[i] && str[i++] != '\n');
  return (i - 1);
}

t_map   *create_map(char *str)
{
  t_map *map;

  map = malloc(sizeof(t_map));
  map->data = str;
  map->width = count_size(str);
  map->height = count_lines(str);
  if (!check_map(map))
    my_putstr_err("Error map size !");
  map->posP = my_getpos_player(str);
  if (!map->posP)
    my_putstr_err("Error map player !");
  create_trigger(map);
  if (!map->size_t)
    my_putstr_err("Error map trigger !");
  return (map);
}
