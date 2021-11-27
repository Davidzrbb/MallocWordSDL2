
#include <pnjService.h>
#include <inits.h>
#include "include\main.h"

int main(int argc, char *args[]) {
    TTF_Init();
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *image = NULL;
    SDL_Texture *fontTitle = NULL;
    SDL_Texture *fontCharge = NULL;
    SDL_Texture *fontNewGame = NULL;
    SDL_Texture *TextureTileMap = NULL;
    int statut = EXIT_FAILURE;
    int resultMouseEvent = 0;
    bool quit = false;
    SDL_Event e;
    SDL_Surface *tileset = NULL;
    SDL_Texture *textuTil = NULL;

    SDL_Color blanc = {255, 255, 255, 255};
    SDL_Rect dstrectCharge = {50, 370, 350, 70};
    SDL_Rect dstrectNewGame = {50, 220, 300, 70};
    SDL_Rect dstrect = {110, 20, 500, 150};

    if (0 != init(&window, &renderer, 700, 520)) /* ecrire cette fonction */
        goto Quit;
    image = loadImage("back.bmp", renderer); /* ecrire cette fonction*/
    tileset = SDL_LoadBMP("tileset1.bmp");
    if (tileset == NULL) {
        fprintf(stderr, "Erreur chargement image droite : %s", SDL_GetError());
        goto Quit;
    }
    textuTil = SDL_CreateTextureFromSurface(renderer, tileset);
    if (textuTil == NULL) {
        fprintf(stderr, "Erreur SDL_CreateTexturetil : %s", SDL_GetError());
        goto Quit;
    }

    setWindowColor(renderer, blanc); /* ecrire cette fonction */
    SDL_QueryTexture(image, NULL, NULL, 0, 0);
    fontTitle = writeTitle(renderer);
    fontCharge = writeNewGame(renderer);
    fontNewGame = writeCharge(renderer);


    statut = EXIT_SUCCESS;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                resultMouseEvent = mouseStartMenu(e);
            }
        }

        if (resultMouseEvent == 0) {
            SDL_RenderCopy(renderer, image, NULL, NULL);
            SDL_RenderCopy(renderer, fontTitle, NULL, &dstrect);
            SDL_RenderCopy(renderer, fontCharge, NULL, &dstrectCharge);
            SDL_RenderCopy(renderer, fontNewGame, NULL, &dstrectNewGame);
        } else if (resultMouseEvent == 2) {
            //NewGame
            // TextureTileMap = Afficher(textuTil);
            SDL_RenderCopy(renderer, TextureTileMap, NULL, NULL);
            //  initStartGame();
        } else {
            SDL_RenderCopy(renderer, image, NULL, NULL);
        }
        SDL_RenderPresent(renderer);
        SDL_UpdateWindowSurface(window);
    }

    Quit:
    if (NULL != image)
        SDL_DestroyTexture(image);
    if (NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if (NULL != window)
        SDL_DestroyWindow(window);

    TTF_Quit();
    SDL_Quit();
    return statut;
}

int init(SDL_Window **window, SDL_Renderer **renderer, int w, int h) {
    if (0 != SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return -1;
    }
    if (0 != SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_SHOWN, window, renderer)) {
        fprintf(stderr, "Erreur SDL_CreateWindowAndRenderer : %s", SDL_GetError());
        return -1;
    }
    return 0;
}

int setWindowColor(SDL_Renderer *renderer, SDL_Color color) {
    if (SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) < 0)
        return -1;
    if (SDL_RenderClear(renderer) < 0)
        return -1;
    return 0;
}

void InitPlayer(Player *firstPlayer) {

    Item *WeaponSword = malloc(sizeof(Item));
    WeaponSword->weapon.name = "epee en bois";
    WeaponSword->weapon.damage = 1;
    WeaponSword->weapon.max_durability = 10;
    WeaponSword->weapon.actual_durabiulity = 10;
    WeaponSword->weapon.id = WOODEN_SWORD;
    WeaponSword->type = WEAPON;

    Item *ToolsPickaxe = malloc(sizeof(Item));
    ToolsPickaxe->tools.name = "pioche en bois";
    ToolsPickaxe->tools.max_durability = 10;
    ToolsPickaxe->tools.actual_durabiulity = 5;
    ToolsPickaxe->tools.id = WOODEN_PICKAXE;
    ToolsPickaxe->type = TOOL;

    Item *ToolsBillhook = malloc(sizeof(Item));
    ToolsBillhook->tools.name = "serpette en bois";
    ToolsBillhook->tools.max_durability = 10;
    ToolsBillhook->tools.actual_durabiulity = 10;
    ToolsBillhook->tools.id = WOODEN_BILLHOOK;
    ToolsBillhook->type = TOOL;


    Item *ToolsAx = malloc(sizeof(Item));
    ToolsAx->tools.name = "hache en bois";
    ToolsAx->tools.max_durability = 10;
    ToolsAx->tools.actual_durabiulity = 10;
    ToolsAx->tools.id = WOODEN_AX;
    ToolsAx->type = TOOL;


    firstPlayer->level = 1;
    firstPlayer->currentHealthPoints = 100;
    firstPlayer->maxHealthpoints = 100;
    firstPlayer->currentExperience = 0;
    firstPlayer->maxExperience = 50;
    firstPlayer->coord_x = 1;
    firstPlayer->coord_y = 0;
    firstPlayer->actual_map = 1;
    firstPlayer->inventory[0] = *WeaponSword;
    firstPlayer->inventory[1] = *ToolsPickaxe;
    firstPlayer->inventory[2] = *ToolsBillhook;
    firstPlayer->inventory[3] = *ToolsAx;
}

void freeStock(PnjLinkedList *stock) {
    if (stock->next != NULL) {
        freeStock(stock->next);
    }
    stock = malloc(sizeof(PnjLinkedList));
    free(stock);
}

