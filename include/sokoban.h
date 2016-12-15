/*
** sokoban.h for my_sokoban in /home/raphael.goulmot/rendu/PSU_2016_my_sokoban
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Thu Dec  8 10:14:02 2016 Raphaël Goulmot
** Last update Thu Dec 15 13:50:37 2016 Raphaël Goulmot
*/

#ifndef SOKOBAN_H_
# define SOKOBAN_H_

# include "map.h"

void	controls(t_map *, int);
void	new_win(t_map *);
void	my_sokoban(char *);
void	my_swap(t_map *, int, int);
void	move_p(t_map *, char, int);
void	rev_trigger(t_map *, int, char);
void	game_win(t_map *);

#endif /* !SOKOBAN_H_ */
