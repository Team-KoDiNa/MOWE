#pragma once

#include <iostream>
#include <vector>
#include <time.h>
#include <future>
#include <pthread.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "header/ParsingJSON.h"

#if WIN32
#include <windows.h>
#else
#include <X11/Xlib.h>
#endif

using namespace std;

class UI : protected parseJSON {
public:
    UI();
    
    int init(bool fullscreen);

    void showImage(SDL_Window* window,string wallpaperDir);
    
private:
    SDL_Renderer * renderer;
    SDL_Window *window;
    SDL_Event event;
    
    int w, h;
};
