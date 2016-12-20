/*
** trigger.c for sokoban in /home/raphael.goulmot/rendu/PSU_2016_my_sokoban
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Dec 13 14:16:42 2016 Raphaël Goulmot
** Last update Tue Dec 13 14:40:50 2016 Raphaël Goulmot
*/

#include "map.h"
#include "trigger.h"
#include "utils.h"
#include <stdlib.h>

int	count_trigger(t_map *map)
{
  int	count;
  int	i;

  count = 0;
  i = 0;
  while (map->data[i++])
    if (map->data[i - 1] == 'O')
      count++;
  return (count);
}

void	create_trigger(t_map *map)
{
  int	i;
  int	pos;

  map->trigger = malloc(sizeof(int) * count_trigger(map));
  pos = 0;
  i  = 0;
  while (map->data[i++])
    if (map->data[i - 1] == 'O')
      map->trigger[pos++] = i - 1;
  map->size_t = pos;
}
