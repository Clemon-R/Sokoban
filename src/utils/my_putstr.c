/*
** my_putstr.c for 102cipher in /home/raphael.goulmot/rendu/102cipher
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 29 16:08:09 2016 Raphaël Goulmot
** Last update Tue Nov 29 16:08:40 2016 Raphaël Goulmot
*/

#include "utils.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i++])
    my_putchar(str[i - 1]);
}
