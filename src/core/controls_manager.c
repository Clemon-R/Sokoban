/*
** controls_manager.c for exam in /home/raphael.goulmot/rendu/PSU_2016_my_sokoban
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Dec 13 10:26:37 2016 Raphaël Goulmot
** Last update Fri Dec 16 17:40:56 2016 Raphaël Goulmot
*/

#include "sokoban.h"
#include "map.h"
#include "utils.h"
#include <ncurses/curses.h>
#include <ncurses.h>
#include <stdlib.h>

void	controls(t_map	*map, int key)
{
  if (key == KEY_UP || key == KEY_DOWN)
    move_p(map, key == KEY_UP, map->width + 1);
  else if (key == KEY_LEFT || key == KEY_RIGHT)
    move_p(map, key == KEY_LEFT, 1);
  game_win(map);
}

void	my_swap(t_map *map, int i1, int i2)
{
  int	tmp;

  tmp = map->data[i1];
  map->data[i1] = map->data[i2];
  map->data[i2] = tmp;
}

void	move_p(t_map *map, char dir, int value)
{
  int   pos;
  int	box;

  pos = map->posP + (dir ? -value : value);
  box = pos + (dir ? -value : value);
  if (((dir && pos >= 0) || (!dir && pos <= my_strlen(map->data)))
      && map->data[pos] != '#')
    {
      if (map->data[pos] == ' ' || map->data[pos] == 'O')
	{
	  rev_trigger(map, pos, 0);
	  my_swap(map, map->posP, pos);
	  rev_trigger(map, map->posP, 1);
	  map->posP = pos;
	}
      else if (map->data[pos] == 'X' && box <= my_strlen(map->data)
	       && map->data[box] != '#')
	{
	  rev_trigger(map, box, 0);
	  my_swap(map, pos, box);
	  my_swap(map, map->posP, pos);
	  rev_trigger(map, box + (dir ? value * 2 : -value * 2) , 1);
	  map->posP = pos;
	}
    }
}

void	rev_trigger(t_map *map, int index, char refresh)
{
  char	check;
  int	i;

  check = 0;
  i = 0;
  while (i++ < map->size_t)
    {
      if (index == map->trigger[i - 1])
	check = 1;
    }
  if (check)
    {
      if (map->data[index] == 'O' && !refresh)
	map->data[index] = ' ';
      else if (map->data[index] == ' ' && refresh)
	map->data[index] = 'O';
    }
}

void	game_win(t_map *map)
{
  int	i;
  char	check;

  i = 0;
  check = 1;
  while (i++ < map->size_t)
    {
      if (map->data[map->trigger[i - 1]] != 'X')
	check = 0;
    }
  if (check)
    {
      endwin();
      my_putstr("Victory !\n");
      exit(0);
    }
}
