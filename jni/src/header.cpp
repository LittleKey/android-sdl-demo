#include "header.hpp"

bool init() {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initializel SDL_Error: %s\n", SDL_GetError());
        success = false;
    } else {
        gWindow = SDL_CreateWindow("SDL Tutorial",
                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                SCREEN_WIDTH, SCREEN_HEIGHT,
                SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            printf("Window counld not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        } else {
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags)) {
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                success = false;
            } else {
                gScreenSurface = SDL_GetWindowSurface(gWindow);
            }
        }
    }
    return success;
}

SDL_Surface* loadSurface(const char* path) {
    SDL_Surface* optimizedSurface = NULL;
    //SDL_Surface* loadedSurface = SDL_LoadBMP(path);
    SDL_Surface* loadedSurface = IMG_Load(path);
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_Error: %s\n", path, SDL_GetError());
    } else {
        optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
        if (optimizedSurface == NULL) {
            printf("Unable to optimize image %s! SDL Error: %s\n", path, SDL_GetError());
        }
        SDL_FreeSurface(loadedSurface);
    }
    return optimizedSurface;
}

bool loadMedia() {
    bool success = true;

    gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("/sdcard/MyPic.png");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL) {
        printf("Failed to load default!\n");
        success = false;
    }
    gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("/sdcard/01.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL) {
        printf("Failed to load default!\n");
        success = false;
    }
    gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("/sdcard/01.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL) {
        printf("Failed to load default!\n");
        success = false;
    }
    gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("/sdcard/01.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL) {
        printf("Failed to load default!\n");
        success = false;
    }
    gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("/sdcard/02.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL) {
        printf("Failed to load default!\n");
        success = false;
    }
    return success;
}

bool loadMediaMouse() {
    bool success = true;

    gMousePressSurfaces[MOUSE_PRESS_SURFACE_DEFAULT] = loadSurface("/sdcard/01.bmp");
    if (gMousePressSurfaces[MOUSE_PRESS_SURFACE_DEFAULT] == NULL) {
        printf("Failed to load default!\n");
        success = false;
    }
    gMousePressSurfaces[MOUSE_PRESS_SURFACE_UP] = loadSurface("/sdcard/01.bmp");
    if (gMousePressSurfaces[MOUSE_PRESS_SURFACE_UP] == NULL) {
        printf("Failed to load up!\n");
        success = false;
    }
    gMousePressSurfaces[MOUSE_PRESS_SURFACE_DOWN] = loadSurface("/sdcard/02.bmp");
    if (gMousePressSurfaces[MOUSE_PRESS_SURFACE_DOWN] == NULL) {
        printf("Failed to load down!\n");
        success = false;
    }
    return success;
}

void close() {
    for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i) {
        SDL_FreeSurface(gKeyPressSurfaces[i]);
        gKeyPressSurfaces[i] = NULL;
    }
    for (int i = 0; i < MOUSE_PRESS_SURFACE_TOTAL; ++i) {
        SDL_FreeSurface(gMousePressSurfaces[i]);
        gMousePressSurfaces[i] = NULL;
    }
    gCurrentSurface = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();
}

SDL_Surface* scaledSurface(int x, int y, int w, int h) {
    SDL_Surface* gStretchedSurface = NULL;
    SDL_Rect stretchRect;
    stretchRect.x = x;
    stretchRect.y = y;
    stretchRect.w = w;
    stretchRect.h = h;
    SDL_BlitScaled(gStretchedSurface, NULL, gScreenSurface, &stretchRect);

    return gStretchedSurface;
}

