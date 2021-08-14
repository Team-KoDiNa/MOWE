#include "header/ui.h"

int UI::init(const char *title, int w, int h, bool fullscreen){
    int flag = 0;
    this -> w = w;
    this -> h = h;
    
    if(fullscreen){
        flag = SDL_WINDOW_FULLSCREEN;
    }
    
}
