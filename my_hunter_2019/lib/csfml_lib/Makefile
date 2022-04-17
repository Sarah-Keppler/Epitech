##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makea lib of graphics ! OF C GRAPHICS !
##

SRC	=	create_window.c	\
		framebuffer.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_strlen.c	\
		init.c		\
		fhunter.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my_csfml.h ../../include/
	cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
