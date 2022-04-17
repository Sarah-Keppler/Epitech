##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make(haha) your own lib !!!!
##

SRC	=	my_putchar.c		\
		my_putstr.c		\
		my_put_nbr.c		\
		my_strlen.c		\
		my_strcpy.c		\
		map.c			\
		get_data.c		\
		move_key.c		\
		movement.c		\
		collision.c		\
		sokoban.c		\
		errors.c		\
		data_errors.c		\
		winning.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../../include/
	cp map.h ../../include/
	cp sokoban.h ../../include/
	cp collision.h ../../include/
	cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
