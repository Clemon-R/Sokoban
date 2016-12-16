/*
** main.c for 102cipher in /home/raphael.goulmot/rendu/102cipher
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 29 16:01:44 2016 Raphaël Goulmot
** Last update Fri Dec 16 14:11:17 2016 Raphaël Goulmot
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
    my_putstr("\tmap\tfile representing the warehouse map");
    my_putstr(", containing '#' for walls,");
    my_putstr("\n\t\t'P' for the player");
    my_putstr(", 'X' for boxes and 'O' for storage locations.\n");
  }
  else
    my_sokoban(argv[1], 0);
  return (0);
}
