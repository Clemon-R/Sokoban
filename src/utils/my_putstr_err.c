/*
** my_purstr_err.c for 102cipher in /home/raphael.goulmot/rendu/102cipher
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 29 16:05:07 2016 Raphaël Goulmot
** Last update Thu Dec 15 13:39:44 2016 Raphaël Goulmot
*/

#include "utils.h"
#include <ncurses/curses.h>
#include <ncurses.h>
#include <stdlib.h>

void	my_putstr_err(char *str)
{
  int	i;

  i = 0;
  endwin();
  while (str[i++])
    my_putchar_err(str[i - 1]);
  exit(84);
}
