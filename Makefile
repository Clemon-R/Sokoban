##
## Makefile for 102cipher in /home/raphael.goulmot/rendu/102cipher
## 
## Made by Raphaël Goulmot
## Login   <raphael.goulmot@epitech.net>
## 
## Started on  Tue Nov 29 15:57:16 2016 Raphaël Goulmot
## Last update Tue Dec 13 15:01:40 2016 Raphaël Goulmot
##

SRC	=	src/utils/my_putchar_err.c	\
		src/utils/my_putstr_err.c	\
		src/utils/my_putchar.c		\
		src/utils/my_putstr.c		\
		src/utils/my_strlen.c		\
		src/core/main.c			\
		src/core/my_sokoban.c		\
		src/core/map.c			\
		src/core/controls_manager.c	\
		src/core/trigger.c		\
		include/utils.h			\
		include/sokoban.h		\
		include/trigger.h		\
		include/map.h

TMP	=	$(OBJ:.h=.h~)

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wextra -Wall -Werror -Iinclude -lncurses

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(TMP)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)
