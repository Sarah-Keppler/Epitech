/*
** EPITECH PROJECT, 2019
** map.h
** File description:
** Header of the map. Thanks to the map, you don't fall into the abyss.
*/

#ifndef MAP_H_
#define MAP_H_

typedef struct s_map {
    char *map;
    char *map_src;
    char **print_map;
    int player_pos;
    int *line_len;
    int len;
    int move;
    int nb_storage;
    int *storage_pos;
    int nb_box;
    int *box_pos;
    int end;
} map_t;

char *read_map(char **, map_t *);
map_t *init_map(char **);
void reset(int, map_t *);
int *get_storages(map_t *);
int *get_boxes(map_t *);
int get_position_on_map(char, char *);
int get_line_player(map_t *);
int *get_len_per_line(map_t *);
void lets_free(map_t *);

#endif /* MAP_H_ */
