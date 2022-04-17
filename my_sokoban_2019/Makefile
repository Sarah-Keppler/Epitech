##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Do you know what Sokoban mean ?
##

SRC	=	my_sokoban.c

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):
	make -C lib/my
	gcc -o $(NAME) $(SRC) -Llib/my -lmy -lncurses -g

clean:
	make -C lib/my clean

fclean: clean
	rm $(NAME)
	make -C lib/my fclean

re:     fclean all
	make -C lib/my fclean all
