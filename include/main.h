#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL_ttf.h>

int init(SDL_Window** window, SDL_Renderer** renderer, int w, int h);
SDL_Texture* loadImage(const char path[], SDL_Renderer* renderer);
int setWindowColor(SDL_Renderer* renderer, SDL_Color color);

