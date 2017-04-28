/*
** my_sokoban.c for my_sokoban in /home/raphael.goulmot/rendu/PSU_2016_my_sokoban
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Thu Dec  8 09:25:42 2016 Raphaël Goulmot
** Last update Tue Mar  7 00:33:01 2017 Raphaël Goulmot
*/

#include "sokoban.h"
#include "utils.h"
#include "map.h"
#include <fcntl.h>
#include <ncurses/curses.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

char	check_refresh(t_map *map, char win)
{
  if (win || !check_map(map))
    {
      if (!win)
	{
	  move((LINES - 1) / 2, (COLS - 38) / 2);
	  printw("Terminal is too small, please resize !");
	}
      else
	{
	  move((LINES - 1) / 2, (COLS - 30) / 2);
	  printw("Push on enter for next level !");
	}
      return (0);
    }
  return (1);
}

void	new_win(t_map *map, char win)
{
  int	len;
  int	i;
  char	c[2];

  clear();
  if (!check_refresh(map, win))
    return;
  len = 0;
  i = 0;
  c[1] = 0;
  move((LINES - map->height) / 2, (COLS - map->width) / 2);
  while (map->data[i])
    {
      if ((i >= map->posP - map->width - 3 && i <= map->posP - map->width + 1)
	  || (i >= map->posP - 2 && i <= map->posP + 2)
	  || (i >= map->posP + map->width - 1 && i <= map->posP + map->width + 3))
	c[0] = map->data[i];
      else
	c[0] = ' ';
      printw(c);
      if (map->data[i] == '\n' && ++len)
	move((LINES - map->height) / 2 + len, (COLS - map->width) / 2);
      i++;
    }
  refresh();
}

char	*my_getlevel(int level)
{
  if (level == 1)
    return ("map1");
  else if (level == 2)
    return ("map2");
  else if (level == 3)
    return ("map2");
  else
    {
      endwin();
      my_putstr("Victory !\n");
      exit(0);
    }
}

char	my_refresh(t_map *map, int key, int level, char *path)
{
  controls(map, key);
  if (game_win(map))
    {
      path = my_getlevel(level + 1);
      my_sokoban(path, level + 1, 1);
      return (0);
    }
  new_win(map, game_win(map));
  return (1);
}

void	my_sokoban(char *path, int level, char reset)
{
  int	fid;
  char	buff[4097];
  int	len;
  int	key;
  t_map	*map;

  fid = open(path, O_RDONLY);
  if (fid < 0 || (len = read(fid, buff, 4096)) == 0)
    my_putstr_err("File error !\n");
  buff[len] = '\0';
  if (!reset)
    initscr();
  map = create_map(buff);
  new_win(map, 0);
  keypad(stdscr, 1);
  cbreak();
  curs_set(0);
  close(fid);
  while ((key = getch()) != 27 && key != ' ')
    {
      if (!my_refresh(map, key, level, path))
	return;
    }
  (key == ' ' ? my_sokoban(path, level, 1) : endwin());
}
