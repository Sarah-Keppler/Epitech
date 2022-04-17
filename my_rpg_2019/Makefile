##
## EPITECH PROJECT, 2019
## Project
## File description:
## Makefile from Lucas Marsala from Kevin Spegt
##
## --------------------------------------------------------------- ##
NAME	=	my_rpg

## --------------------------------------------------------------- ##
PATH_LIB	=	./lib/my/
LIB	=	get_next_line.c         \
                my_math.c               \
                my_rand.c               \
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
PATH_RPG	=	./sources/
RPG	=	main.c                  \
		armor.c                 \
                inventory.c		\
		dragon_quest.c		\
		menu.c			\
		inventory_menu.c	\
		profil_menu.c

PATH_IPF        =       ./sources/init_print_free/
IPF     =       free_rpg.c              \
                get_files_sources.c     \
                init_dialogue.c         \
                init_item.c             \
                init_objectif.c         \
                init_player.c           \
		set_info_player.c	\
                init_pnj.c              \
                init_quest.c            \
                init_reward.c           \
		init_battle.c		\
                init_rpg.c              \
                init_rpg_part1.c        \
                init_rpg_part2.c        \
                init_rpg_part3.c        \
                init_rpg_part4.c        \
                init_set.c              \
                init_stat.c             \
		init_map.c		\
		init_attack.c		\
		init_monster.c		\
                ipf_inventory.c         \
                print_object.c          \
                print_person.c          \
                print_quest.c           \
		print_map.c		\
                print_rpg.c		\
		print_player.c

PATH_FIND	=	./sources/find_ref/
FIND	=	find_ref_object.c       \
                find_ref_person.c       \
                find_ref_quest.c	\
		find_ref_map.c		\
		find_ref_sprite.c

PATH_MAP	=	./sources/map/
MAP	=	anim_movement.c		\
		move.c			\
		engage_movement.c	\
		position.c		\
		event.c

PATH_COMBAT	=	./sources/combat/
COMBAT	=	attack.c	\
		choose.c	\
		draw_battle.c	\
		engage_combat.c

PATH_GRAPH	=	./sources/init_print_free/csfml/
GRAPH	=	sprite.c	\
		text.c

PATH_THEO	=	./sources/theo/
THEO	=	check.c			\
		click_gestion.c		\
		create.c		\
		create_menu.c		\
		create_option.c		\
		create_pause.c		\
		create_play_menu.c	\
		menu.c			\
		option_gestion.c	\
		particle.c		\
		particle_gest.c		\
		home.c			\
		init_home.c		\
		destroy.c		\
		modif_particle.c

## --------------------------------------------------------------- ##
SRC	=	$(addprefix $(PATH_LIB), $(LIB))	\
		$(addprefix $(PATH_RPG), $(RPG))	\
		$(addprefix $(PATH_IPF), $(IPF))	\
		$(addprefix $(PATH_FIND), $(FIND))	\
		$(addprefix $(PATH_MAP), $(MAP))	\
		$(addprefix $(PATH_COMBAT), $(COMBAT))	\
		$(addprefix $(PATH_THEO), $(THEO))	\
		$(addprefix $(PATH_GRAPH), $(GRAPH))

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
	-lcsfml-system -lcsfml-audio

## --------------------------------------------------------------- ##
clean:
	rm -f $(OBJ)
	@printf "$(GREEN)\n$(WHITE)"
	@printf "$(GREEN)  [$(WHITE)$(NAME)$(GREEN)] -> "
	@printf "$(WHITE)Suppression terminée.\n\n"

pizza:
	rm -f *~ vgcore.* *.o
	rm -f $(PATH_RPG)*~ $(PATH_RPG)*.o
	rm -f $(PATH_IPF)*~ $(PATH_IPF)*.o
	rm -f $(PATH_FIND)*~ $(PATH_FIND)*.o
	rm -f $(PATH_MAP)*~ $(PATH_MAP)*.o
	rm -f $(PATH_COMBAT)*~ $(PATH_COMBAT)*.
	rm -f $(PATH_THEO)*~ $(PATH_THEO)*.o
	rm -f $(PATH_GRAPH)*~ $(PATH_GRAPH)*.o
	rm -f $(PATH_LIB)*~ $(PATH_LIB)*.o
	rm -f ./include/*~ ./include/*.o
	rm -f ./database/*~

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
