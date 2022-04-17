##
## EPITECH PROJECT, 2019
## World
## File description:
## Makefile from Lucas Marsala from Kevin Spegt
##
## --------------------------------------------------------------- ##
NAME	=	my_world

## --------------------------------------------------------------- ##
PATH_LIB	=	./lib/my/
LIB	=	get_next_line.c         \
                my_math.c               \
                my_read.c               \
                my_strcat.c             \
                my_strcmp.c             \
                my_strcpy.c             \
                my_str_is.c             \
                my_str_to_word_array.c  \
                my_swaps.c              \
                my_write.c              \
                my_write_number.c       \
                number.c                \
                str_manipulation.c      \
                tab_and_spaces.c

## --------------------------------------------------------------- ##
PATH_WORLD	=	./sources/
WORLD	=	main.c				\
		button.c			\
		home.c				\
		sprite.c			\
		world.c				\
		state_hover_home.c		\
		home_page.c			\
		import.c			\
		check_map.c			\
		threedmap_and_twodmap.c		\
		editor.c			\
		edit.c				\
		color.c				\
		state_hover_edit.c		\
		check_tiles.c			\
		mouse.c				\
		check_first_tiles.c		\
		shape.c				\
		vertex_array.c			\
		draw_editor.c			\
		color_tiles_and_corners.c	\
		check_corners.c			\
		wireframe_and_arrays.c		\
		draw_tiles.c			\
		map_manipulation.c		\
		my_free_and_destroy.c		\
		update_maps.c			\
		lower.c				\
		raise.c				\
		map_translation.c		\
		shortcut.c			\
		change_map.c			\
		tiles_and_corners.c

## --------------------------------------------------------------- ##
SRC	=	$(addprefix $(PATH_LIB), $(LIB))	\
		$(addprefix $(PATH_WORLD), $(WORLD))

## --------------------------------------------------------------- ##
REDDARK	=	\033[31;1m
REDDARK =       \033[31;1m
RED     =       \033[31;1m
GREEN   =       \033[32;1m
YEL     =       \033[33;1m
BLUE    =       \033[34;1m
PINK    =       \033[35;1m
CYAN    =       \033[36;1m
WHITE   =       \033[0m

## --------------------------------------------------------------- ##
OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g		\
		-W		\
		-Wall		\
		-Wextra		\
		-Werror		\
		-pedantic	\
		-I./include/

## --------------------------------------------------------------- ##
all:	$(NAME)
	@printf	"$(GREEN)\n$(WHITE)"
	@printf "$(GREEN)  [$(WHITE)$(NAME)$(GREEN)] -> "
	@printf "$(WHITE)Compilation terminée."
	@printf "$ Binaire : $(CYAN) ./%s$(WHITE)\n\n" $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window	\
	-lcsfml-system -lm

## --------------------------------------------------------------- ##
clean:
	rm -f $(OBJ)
	@printf "$(GREEN)\n$(WHITE)"
	@printf "$(GREEN)  [$(WHITE)$(NAME)$(GREEN)] -> "
	@printf "$(WHITE)Suppression terminée.\n\n"

pizza:
	rm -f *~
	rm -f vgcore.*

fclean:	pizza clean
	rm -f $(NAME)

re:	fclean all

.PHONY: re clean fclean all pizza

## ========================================================================= ##
%.o:    %.c
	@printf "$(GREEN)[$(WHITE)$(NAME)$(GREEN)] — $(WHITE)%-45s\n" $<
	@printf "$(GREEN) → $(RES) %-50s" $@
	@printf "$(GREEN)[$(WHITE)√$(GREEN)]\n\n"
	@gcc $(CFLAGS) -o $@ -c $<
