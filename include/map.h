/*
** map.h for sokoban in /home/raphael.goulmot/rendu/PSU_2016_my_sokoban
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Dec 13 10:48:52 2016 Raphaël Goulmot
** Last update Tue Dec 13 14:27:15 2016 Raphaël Goulmot
*/

#ifndef MAP_H_
# define MAP_H_

typedef struct	s_map
{
  char	*data;
  int	posP;
  int	width;
  int	height;
  int	*trigger;
  int	size_t;
}		t_map;

t_map	*create_map(char *);
char	check_map(t_map *);
int	count_lines(char *);
int	count_size(char *);
int	my_getpos_player(char *);

#endif /* !MAP_H_ */
