#include "include\main.h"

#undef main

int main(int argc, char *args[]) {
     TTF_Init();

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *image = NULL;
    int statut = EXIT_FAILURE;
    bool quit = false;
    SDL_Event e;

    SDL_Color blanc = {255, 255, 255, 255};
    if (0 != init(&window, &renderer, 700, 520)) /* ecrire cette fonction */
        goto Quit;

    image = loadImage("back.bmp", renderer); /* ecrire cette fonction*/
    setWindowColor(renderer, blanc); /* ecrire cette fonction */
    SDL_QueryTexture(image, NULL, NULL, 0, 0);
    SDL_RenderCopy(renderer, image, NULL, NULL);
    SDL_RenderPresent(renderer);

    TTF_Font *font = TTF_OpenFont("arial.ttf", 25);
    SDL_Color color = {255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Solid(font, "Malloc Word !", color);
    SDL_Texture *textureFont = SDL_CreateTextureFromSurface(renderer, surface);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(textureFont, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = {110, 20, 500, 200};
    SDL_RenderCopy(renderer, textureFont, NULL, &dstrect);
    SDL_RenderPresent(renderer);


    statut = EXIT_SUCCESS;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
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

int setWindowColor(SDL_Renderer *renderer, SDL_Color color) {
    if (SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) < 0)
        return -1;
    if (SDL_RenderClear(renderer) < 0)
        return -1;
    return 0;
}
