/*
** my_strlen.c for sokoban in /home/raphael.goulmot/rendu/PSU_2016_my_sokoban
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Dec 13 13:43:57 2016 Raphaël Goulmot
** Last update Tue Dec 13 13:44:32 2016 Raphaël Goulmot
*/

#include "utils.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i++]);
  return (i);
}
