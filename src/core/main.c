/*
** main.c for 102cipher in /home/raphael.goulmot/rendu/102cipher
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 29 16:01:44 2016 Raphaël Goulmot
** Last update Tue Dec 13 09:47:00 2016 Raphaël Goulmot
*/

#include "utils.h"
#include "sokoban.h"

int	main(int argc, char **argv)
{
  if (argc < 2)
    my_putstr_err("Error parameters !\n");
  if (argv[1][0] == '-' && argv[1][1] == 'h')
  {
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfile representing the warehouse map, containing '#' for walls,");
    my_putstr("\n\t'P' for the player, 'X' for boxes and 'O' for storage locations.\n");
  }
  else
    my_sokoban(argv[1]);
  return (0);
}