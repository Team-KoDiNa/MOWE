#pragma once

#include <iostream>
#include <vector>
#include <time.h>
#include <future>
#include <pthread.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

#if WIN32
#include <windows.h>
#else
#include "gtk/gtkx.h"
#endif

class UI {
public:
    UI();
    
    int init(const char *title, int w, int h, bool fullscreen);

    void render();
    void cleanRenderer();
    void clean();
    
private:
    SDL_Renderer * renderer;
    SDL_Window *window;
    SDL_Event event;
    
    int w, h;
};
