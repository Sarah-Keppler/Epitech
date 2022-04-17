/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** Struct of my_world.
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct sprite_s {
    sfSprite *sprite;
    sfTexture *text;
} sprite_t;

typedef struct button_s {
    int state;
    sfIntRect rect;
    sfFloatRect rectf;
    sprite_t *entity;
} button_t;

typedef struct mouse_s {
    float radius;
    char draw_circles;
    sfCircleShape *circle;
    char tiles;
    sfVector2f points[4];
    float distance;
} mouse_t;

typedef struct map_s {
    int **map_3d;
    sfVector2f **map_2d;
    int width;
    int height;
} map_t;

#define EDIT_BUTTON 21
#define BACKGROUND_PAUSED "Assets/menu_paused_final.png"

typedef struct edit_s {
    sprite_t *background;
    button_t **ref_button;
    map_t *map;
    mouse_t *mouse;
} edit_t;

#define HOME_BUTTON 3

typedef struct home_s {
    sprite_t *background;
    button_t **ref_button;
    int load_map;
    map_t *map;
    char **av;
} home_t;

#define COLOR_MAX 6

typedef struct color_s {
    sfColor *colors;
    char *color_names[COLOR_MAX];
} color_t;

typedef struct world_s {
    sfRenderWindow *window;
    sfEvent event;
    int load_scene;
    sfClock *clock;
    sfTime frametime;
    button_t **buttons;
    color_t *ref_color;
    home_t *home;
    edit_t *edit;
} world_t;

#define BUTTON_MAX 24

enum nbutton {
    NEWMAP,
    LOADMAP,
    EXIT,
    UP,
    DOWN,
    RIGHT,
    LEFT,
    CIRCLE,
    POINT,
    SQUARE,
    AMP_UP,
    AMP_DOWN,
    IN_AREA,
    DE_AREA,
    IN_MAP,
    DE_MAP,
    MENU,
    IMPORT,
    EXPORT,
    SAVE,
    ROTATE_R,
    ROTATE_L,
    IN_ZOOM,
    DE_ZOOM
};

#define BACKGROUND "Assets/background_menu_final.png"
#define BUTTON_NEWMAP "Assets/boutton_newmap_states.png"
#define BUTTON_LOADMAP "Assets/boutton_loadmap_states.png"
#define BUTTON_EXIT "Assets/boutton_exit_states.png"
#define BACKGROUND_GUI "Assets/background_gui_2.png"
#define BUTTON_UP "Assets/button_up_arrow_states.png"
#define BUTTON_DOWN "Assets/button_down_arrow_states.png"
#define BUTTON_RIGHT "Assets/button_right_arrow_states.png"
#define BUTTON_LEFT "Assets/button_left_arrow_states.png"
#define BUTTON_CIRCLE "Assets/button_circle_states.png"
#define BUTTON_POINT "Assets/button_point_states.png"
#define BUTTON_SQUARE "Assets/button_square_states.png"
#define BUTTON_IMPORT "Assets/button_import_states.png"
#define BUTTON_EXPORT "Assets/button_export_states.png"
#define BUTTON_SAVE "Assets/button_save_states.png"
#define BUTTON_AMP_UP "Assets/button_amplitude_up_states.png"
#define BUTTON_AMP_DOWN "Assets/button_amplitude_down_states.png"
#define BUTTON_MENU "Assets/button_menu_states.png"
#define BUTTON_IN_AREA "Assets/button_augmenter_states.png"
#define BUTTON_DE_AREA "Assets/button_diminuer_states.png"
#define BUTTON_IN_MAP "Assets/button_map_plus_states.png"
#define BUTTON_DE_MAP "Assets/button_map_moins_states.png"
#define BUTTON_ROTATE_R "Assets/button_rotation_right_states.png"
#define BUTTON_ROTATE_L "Assets/button_rotation_left_states.png"
#define BUTTON_IN_ZOOM "Assets/button_zoom_plus_states.png"
#define BUTTON_DE_ZOOM "Assets/button_zoom_moins_states.png"

#endif /* STRUCT_H_ */
