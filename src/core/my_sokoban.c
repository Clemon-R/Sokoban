/*
** my_sokoban.c for my_sokoban in /home/raphael.goulmot/rendu/PSU_2016_my_sokoban
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Thu Dec  8 09:25:42 2016 Raphaël Goulmot
** Last update Fri Dec 16 14:22:22 2016 Raphaël Goulmot
*/

#include "sokoban.h"
#include "utils.h"
#include "map.h"
#include <fcntl.h>
#include <ncurses/curses.h>
#include <ncurses.h>
#include <unistd.h>

void	new_win(t_map *map)
{
  int	len;
  int	i;
  char	c[2];

  clear();
  if (!check_map(map))
    {
      move((LINES - 1) / 2, (COLS - 38) / 2);
      printw("Terminal is too small, please resize !");
      return;
    }
  len = 0;
  i = 0;
  c[1] = '\0';
  move((LINES - map->height) / 2, (COLS - map->width) / 2);
  while (map->data[i++])
    {
      c[0] = map->data[i - 1];
      printw(c);
      if (map->data[i - 1] == '\n' && ++len)
	move((LINES - map->height) / 2 + len, (COLS - map->width) / 2);
    }
  refresh();
}

void	my_sokoban(char *path, char reset)
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
  new_win(map);
  keypad(stdscr, 1);
    cbreak();
  curs_set(0);
  while ((key = getch()) != 27 && key != ' ')
    {
      controls(map, key);
      new_win(map);
    }
  (key == ' ' ? my_sokoban(path, 1) : endwin());
  close(fid);
}
