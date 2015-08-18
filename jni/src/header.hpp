#ifndef HEADER
#define HEADER
#include "SDL.h"
#include <stdio.h>
#include <stdbool.h>
//#include <SDL2_image/SDL_image.h>
#include <unistd.h>
#include <stdlib.h>
#include <jni.h>
#include "SDL_main.h"
#include "SDL_image.h"
#include <string.h>

#ifdef __cplusplus
extern "C"
#endif

int SCREEN_WIDTH = 0;
int SCREEN_HEIGHT = 0;

enum KeyPressSurface {
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

enum MousePressSurface {
    MOUSE_PRESS_SURFACE_DEFAULT,
    MOUSE_PRESS_SURFACE_UP,
    MOUSE_PRESS_SURFACE_DOWN,
    MOUSE_PRESS_SURFACE_TOTAL
};

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gCurrentSurface = NULL;
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
SDL_Surface* gMousePressSurfaces[MOUSE_PRESS_SURFACE_TOTAL];

bool init();

bool loadMedia();
bool loadMediaMouse();

SDL_Surface* loadSurface(const char* path);

void close();
#endif
