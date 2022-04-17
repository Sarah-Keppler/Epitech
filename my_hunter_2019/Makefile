##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Create a buttom to load the game ! (without buges hopefully)
##

SRC	=	my_hunter.c

NAME	=	my_hunter

all:	$(NAME)

$(NAME):
	make -C lib/csfml_lib all
	gcc -o $(NAME) $(SRC) -Llib/csfml_lib -lmy -lcsfml-graphics -lcsfml-system

clean:
	make -C lib/csfml_lib clean

fclean:	clean
	make -C lib/csfml_lib fclean

re:	fclean all
