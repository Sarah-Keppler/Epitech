/*
** EPITECH PROJECT, 2019
** project.h
** File description:
** Header of the project.
*/

#ifndef PROJECT_H_
#define PROJECT_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"
#include "proto.h"

/*---SCREEN---*/
#define SCREEN_H 840
#define SCREEN_W 1320

/*---PATH---*/
#define DIALOGUE_PATH "database/Dialogues/"
#define ITEM_PATH "database/Items/"
#define PNJ_PATH "database/PNJs/"
#define QUEST_PATH "database/Quests/"
#define OBJECTIF_PATH "database/Objectifs/"
#define REWARD_PATH "database/Rewards/"
#define SET_PATH "database/Sets/"
#define MAP_PATH "database/Maps/"
#define ATTACK_PATH "database/Attacks/"
#define MONSTER_PATH "database/Monsters/"

/*---PLAYER---*/
#define PLAYER_I "Assets/mario.png"
#define PLAYER_H 64
#define PLAYER_W 47
#define UP_M 0
#define RIGHT_M 1
#define DOWN_M 2
#define LEFT_M 3

/*---EVENTS---*/
#define INVENT_EVENT 1
#define COMBAT_EVENT 0
#define PROFIL_EVENT 2

/*---MONSTER---*/
#define MONSTER_I "Assets/lich_king.png"
#define MONSTER_S 256

/*---MAPS---*/
#define BLOCK 16
#define NOTSPE "5"
#define DENIED "0"
#define MAP1 "Assets/MAP1.png"
#define MAP2 "Assets/MAP2.png"

/*---DIALOGUES---*/
#define CHAR_MAX 50

/*---HOME---*/
#define HOME_BG "Assets/Home/background.jpg"
#define PLAY_TEXT "Appuyer sur espace pour jouer"
#define QUIT_TEXT "Appuyer sur echap pour quitter"

/*---BATTLE---*/
#define OPTION_MAX 2
#define BATTLE_I "Assets/battle_bg.jpg"
#define MENU_I "Assets/box.png"
#define CACHE_I "Assets/cursor.png"
#define WIN 0
#define LOSE -1
#define CLOSE -2

/*---INVENTORY---*/
#define SET_INDEX 1
#define INVENT_I "Assets/box.png"
#define CLOSE_I "Assets/close.png"

/*---FONT---*/
#define RAVENNA_F "Assets/Home/Ravenna.ttf"
#define ARIAL_F "Assets/arial.ttf"

/*---SPRITES---*/
#define SPRITE1 "Assets/epitech.png"
#define SPRITE2 "Assets/set1.png"
#define SPRITE3 "Assets/plast.png"
#define SPRITE4 "Assets/jambes.png"
#define SPRITE5 "Assets/pieds.png"
#define SPRITE6 "Assets/set5.png"

/*---THEO---*/
#define MUSIC "Assets/Home/dq6-sfc.ogg"
#define PASSED_ON_B "Assets/Home/button_passed_on.png"
#define MENU1_I "Assets/Home/menu_bg.png"
#define PIXEL_F "Assets/pixel.ttf"
#define MENU2_I "Assets/Home/play_menu_bg.png"

#endif /* PROJECT_H_ */
