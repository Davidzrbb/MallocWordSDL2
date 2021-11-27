

#ifndef MALLOC_WORLD_MAIN_H
#define MALLOC_WORLD_MAIN_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "startMenu.h"


int init(SDL_Window **window, SDL_Renderer **renderer, int w, int h);

SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer);

int setWindowColor(SDL_Renderer *renderer, SDL_Color color);



struct Armor {
    int id;
    char *name;
    int protection;
};
typedef struct Armor Armor;

enum armor {
    STONE_CHESTPLATE = 11,
    IRON_CHESTPLATE = 22,
    DIAMOND_CHESTPLATE = 33,
};
typedef enum armor armor;

struct healthPotion {
    int id;
    char *name;
    int quantity;
    int pvRestore;
};
typedef struct healthPotion healthPotion;

enum enumHealthPotion {
    HEAL1 = 15,
    HEAL2 = 26,
    HEAL3 = 34,
};
typedef enum enumHealthPotion enumHealthPotion;

struct Weapon {
    int id;
    char *name;
    int damage;
    float max_durability;
    float actual_durabiulity;
};
typedef struct Weapon Weapon;

struct Tools {
    int id;
    char *name;
    float max_durability;
    float actual_durabiulity;
};
typedef struct Tools Tools;

struct Resource {
    int id;
    char *name;
    int quantity;
};
typedef struct Resource Resource;


struct Item {
    int type;
    union {
        struct Weapon weapon;
        struct Tools tools;
        struct Resource resource;
        struct Armor armor;
        struct healthPotion heal;
    };
};
typedef struct Item Item;

struct Player {
    int level;
    int currentExperience;
    int maxExperience;
    float currentHealthPoints;
    float maxHealthpoints;
    int actual_map;
    int coord_x;
    int coord_y;
    Item currentWeapon;
    Item inventory[10];
};
typedef struct Player Player;


enum entity {
    PORTAL1_2 = -3,
    PORTAL2_3 = -2,
    IMPASSABLE = -1,
    FREE = 0,
    PLAYER = 1,
    NPC = 2,
    PLANT1 = 3,
    ROCK1 = 4,
    WOOD1 = 5,
    PLANT2 = 6,
    ROCK2 = 7,
    WOOD2 = 8,
    PLANT3 = 9,
    ROCK3 = 10,
    WOOD3 = 11,
    END8BOSS = 99,
};
typedef enum entity entity;

enum resource {
    FIR = 5,
    ROCK = 6,
    GRASS = 7,
    BEECH = 16,
    IRON = 17,
    LAVANDER = 18,
    OAK = 27,
    DIAMOND = 28,
    HEMP = 29,
};
typedef enum resource resource;
enum weaponEnum {
    WOODEN_SWORD = 1,
    STONE_SWORD = 8,
    STONE_SPEAR = 9,
    STONE_HAMMER = 10,
    IRON_SWORD = 19,
    DIAMOND_SWORD = 30,
    IRON_SPEAR = 20,
    DIAMOND_SPEAR = 31,
    IRON_HAMMER = 21,
    DIAMOND_HAMMER = 32,
};
typedef enum weaponEnum weaponEnum;
enum tools {
    WOODEN_PICKAXE = 2,
    WOODEN_BILLHOOK = 3,
    WOODEN_AX = 4,
    STONE_PICKAXE = 12,
    STONE_BILLHOOK = 13,
    STONE_AX = 14,
    IRON_PICKAXE = 23,
    IRON_BILLHOOK = 24,
    IRON_AX = 25,
};
typedef enum tools tools;
enum type {
    WEAPON = 1,
    TOOL = 2,
    RESOURCE = 3,
    HEAL = 4,
    ARMOR = 5,
};
typedef enum type type;

struct Monster {
    int id;
    char *name;
    int currentLife;
    int maxLife;
    float damage;
    int experience;
    int zone;
};
typedef struct Monster Monster;

struct AllMonster {
    Monster allMonster[10];
};

typedef struct AllMonster AllMonster;

static int mapsSize[3] = {8, 10, 12};

void InitPlayer(Player *);

void printTest(Player);

void attackPlayer(Player *player, Monster *monster, Weapon *);

void attackMonster(Player *player, Monster *monster);

void addLevel(Player *player);

void initMonster(AllMonster *);

void printMonster(AllMonster);

Weapon weaponChoice(Player *);

void combat(Player *, Monster *);

void printHealth(Player *player, Monster *monster);

int **createTable(int size);

void fill_tab(int **tab, int size_line, int size_col);

void printTest(Player);

#endif
