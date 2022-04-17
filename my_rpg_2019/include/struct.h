/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** Hearders of the rpg.
*/

#ifndef STRUCT_H_
#define STRUCT_H_

            /*###############*/
            /*     CSFML     */
            /*###############*/

typedef struct sprite_s {
    sfSprite *sprite;
    sfTexture *text;
} sprite_t;

            /*##############*/
            /*     MAPS     */
            /*##############*/

typedef struct map_s {
    sprite_t *bg;
    char **collisions;
} map_t;

            /*###################*/
            /*     DIALOGUES     */
            /*###################*/

typedef struct dbox_s {
    char **lines;
    int *separation;
} dbox_t;

typedef struct dialogue_s {
    char **scripts;
    char **selections;
} dialogue_t;

            /*###############*/
            /*     STATS     */
            /*###############*/

typedef struct stat_s {
    int attack;
    int def;
    int critical;
    int strengh;
    int intelligent;
    int agility;
} stat_t;

            /*################*/
            /*     OBJECTS     */
            /*################*/

typedef enum {
    combat,
    standart,
    quest_object,
} type_item;

typedef enum {
    nothing,
    heal_e,
    healing_e,
    attack_e,
    def_e,
} obj_effects;

typedef enum {
    tete,
    epaule,
    torse,
    jambes,
    pieds,
    cape,
    arme,
} set_type;

typedef struct item_s {
    char *name;
    char *description;
    type_item type;
    obj_effects effect;
    char saleable;
    int cost;
} item_t;

typedef struct set_s {
    char *name;
    char *description;
    set_type type;
    stat_t *stat;
    char saleable;
    int cost;
} set_t;

typedef struct object_s {
    sprite_t *entity;
    set_t *set;
    item_t *item;
} object_t;

typedef struct inventory_s {
    sprite_t *bg;
    sfText **texts;
    sprite_t *close;
    int places;
    int occupied;
    object_t **items;
} inventory_t;

          /*################*/
          /*     QUESTS     */
          /*################*/

typedef struct reward_s {
    int exp;
    int money;
    set_t *set;
    item_t *item;
} reward_t;

typedef enum {
    not_begin,
    begin,
    completed,
    rendered,
} quest_state;

typedef enum {
    kill,
    recolt,
    talk,
} type_objectif;

typedef struct objectif_s {
    char *description;
    type_objectif type;
    int number;
    int current_number;
} objectif_t;

typedef struct quest_s {
    char *name;
    char *description;
    objectif_t *objectif;
    quest_state state;
    reward_t *reward;
} quest_t;

          /*#################*/
          /*     COMBATS     */
          /*#################*/

typedef enum {
    basique,
    special,
    sorts,
} type_attack;

typedef enum {
    empoissonement,
    stun,
    heal,
    healing,
} effet_spe;

typedef struct attack_s {
    char *name;
    char *description;
    int damage;
} attack_t;

          /*################*/
          /*     HEROES     */
          /*################*/

typedef struct player {
    char *name;
    sprite_t *entity;
    sprite_t *bg;
    sprite_t *close;
    sfText *infos[10];
    int life[2];
    int pos[2];
    int level;
    int exp[2];
    set_t *armor[7];
    int money;
    inventory_t *inventory;
    attack_t **attacks;
} player_t;

typedef enum {
    hero,
    merchant,
    citizen,
} pnj_type;

typedef struct pnj {
    char *name;
    pnj_type type;
    int level;
    int exp;
    int exp_max;
    quest_t **quest;
    dialogue_t *dialogues;
} pnj_t;

typedef struct monster_s {
    char *name;
    sprite_t *entity;
    int life[2];
    attack_t **attacks;
    int reward_xp;
} monster_t;

          /*##############*/
          /*     MENU     */
          /*##############*/

typedef struct menu_s {
    sprite_t *bg;
    sfText **texts;
    sfFont *font;
    sprite_t *cache;    
} menu_t;

typedef struct battle_s {
    menu_t *menu[2 + 1];
    sprite_t *bg;
    attack_t *attack;
    int display;
    int end;
    sfFont *font;
    player_t *player;
    monster_t *monster;
} battle_t;
/*
typedef struct home_s {
    sprite_t *bg;
    sfFont *font;
    sfText **texts;
    } home_t;*/

typedef struct rpg_s {
    sfRenderWindow *window;
    sfEvent event;
    int events[3];
    sfClock *clock;
    sfTime frame;
    int load;
    map_t *map;
    attack_t *attacks[4 + 1];
    map_t *maps[2 + 1];
    dialogue_t *dialogues[1 + 1];
    item_t *items[1 + 1];
    pnj_t *pnjs[1 + 1];
    monster_t *monsters[1 + 1];
    quest_t *quests[1 + 1];
    objectif_t *objectifs[1 + 1];
    reward_t *rewards[1 + 1];
    set_t *sets[5 + 1];
    sprite_t *sprites[6 + 1];
} rpg_t;

typedef struct particle_s
{
    int inc;
    sfUint8 *pixels;
    sfVector2f position;
    sfSprite *sprite;
    struct particle_s *next;
    struct particle_s *first;
} particle_t;

typedef struct button_s
{
    sfSprite *but;
    sfText *text;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect value;
    int ret;
} button_t;

typedef struct scene_s
{
    int button_pressed;
    button_t **but;
    sprite_t *cache;
    sfVector2f cache_pos;
    sprite_t *background;
    struct scene_s *next;
    struct scene_s *prev;
} scene_t;

typedef struct home_s {
    int nb;
    scene_t *scene;
    particle_t *part;
    sfMusic *music;
} home_t;

#endif /* STRUCT_H_ */
