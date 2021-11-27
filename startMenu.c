#include "main.h"
#include "startMenu.h"

SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer) {
    SDL_Surface *tmp = NULL;
    SDL_Texture *texture = NULL;
    tmp = SDL_LoadBMP(path);
    if (NULL == tmp) {
        fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
        return NULL;
    }
    texture = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);
    if (NULL == texture) {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        return NULL;
    }
    return texture;
}
SDL_Texture * writeTitle(SDL_Renderer *renderer) {
    TTF_Font *font = TTF_OpenFont("arial.ttf", 25);
    SDL_Color color = {255, 255, 255};
    //TITLE
    SDL_Surface *tile = TTF_RenderText_Solid(font, "Malloc Word !", color);
    SDL_Texture *textureFont = SDL_CreateTextureFromSurface(renderer, tile);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(textureFont, NULL, NULL, &texW, &texH);
    
    return textureFont;
}
SDL_Texture * writeNewGame(SDL_Renderer *renderer) {
    TTF_Font *font = TTF_OpenFont("arial.ttf", 25);
    SDL_Color color = {255, 255, 255};

    //Button
    SDL_Surface *tile = TTF_RenderText_Solid(font, "Nouvelle partie !", color);
    SDL_Texture* textureFont = SDL_CreateTextureFromSurface(renderer, tile);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(textureFont, NULL, NULL, &texW, &texH);

    return textureFont;
}
SDL_Texture * writeCharge(SDL_Renderer *renderer) {
    TTF_Font *font = TTF_OpenFont("arial.ttf", 25);
    SDL_Color color = {255, 255, 255};

    //Button
    SDL_Surface *tile = TTF_RenderText_Solid(font, "Charge !", color);
    SDL_Texture* textureFont = SDL_CreateTextureFromSurface(renderer, tile);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(textureFont, NULL, NULL, &texW, &texH);

    return textureFont;
}

int mouseStartMenu(SDL_Event e) {
    if (e.button.button == SDL_BUTTON_LEFT && e.button.x >= 50 && e.button.x <= 350 && e.button.y >= 220 &&
        e.button.y <= 290) {
        printf("CHARGE");
        return 1;
    }
    if (e.button.button == SDL_BUTTON_LEFT && e.button.x >= 50 && e.button.x <= 400 && e.button.y >= 380 &&
        e.button.y <= 450) {
        printf("Nouvelle partie");
    }
}