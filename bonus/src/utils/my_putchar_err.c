/*
** my_putchar_err.c for 102cipher in /home/raphael.goulmot/rendu/102cipher
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 29 16:03:52 2016 Raphaël Goulmot
** Last update Tue Nov 29 16:07:24 2016 Raphaël Goulmot
*/

#include <unistd.h>
#include "utils.h"

void	my_putchar_err(char c)
{
  write(2, &c, 1);
}
