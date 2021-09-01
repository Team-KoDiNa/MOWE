#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

//include header as which OS
#if WIN32
#include <windows.h>
#else
#include <CoreGraphics/CGDisplayConfiguration.h>
#endif

int main(int argc, const char * argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("error initailizing SDL: %s\n",SDL_GetError());
        return 1;
    }
    
    
    return 0;
}

int* getScreenSize(){
    static int resolution[2];
    
    return resolution;
}

/*
     --todo--
     1. parsing JSON <- done
     2. decide how to organize a wallpaper folder <- done
     3. make code with ffmpeg(doing. . .)
     4. edit WallaperUI.cpp & ParingJSON.cpp (becuz i make code like shxt)
*/
