/*
** sokoban.h for my_sokoban in /home/raphael.goulmot/rendu/PSU_2016_my_sokoban
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Thu Dec  8 10:14:02 2016 Raphaël Goulmot
** Last update Fri Dec 16 19:06:10 2016 Raphaël Goulmot
*/

#ifndef SOKOBAN_H_
# define SOKOBAN_H_

# include "map.h"

void	controls(t_map *, int);
void	new_win(t_map *, char);
void	my_sokoban(char *, int, char);
void	my_swap(t_map *, int, int);
void	move_p(t_map *, char, int);
void	rev_trigger(t_map *, int, char);
char	game_win(t_map *);

#endif /* !SOKOBAN_H_ */
