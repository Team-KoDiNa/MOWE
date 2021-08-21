#include "header/WallpaperUI.h"

#if _WIN32 || _WIN64
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    HWND p = FindWindowEx(hwnd, NULL, "SHELLDLL_DefView", NULL);
    HWND* ret = (HWND*)lParam;

    if (p) {
        // Gets the WorkerW Window after the current one.
        *ret = FindWindowEx(NULL, hwnd, "WorkerW", NULL);
        }
    return true;
}

HWND get_wallpaper_window(){
    HWND progman = FindWindow("ProgMan", NULL);
    SendMessageTimeout(progman, 0x052C, 0, 0, SMTO_NORMAL, 1000, nullptr);
    HWND wallpaper_hwnd = nullptr;
    EnumWindows(EnumWindowsProc, (LPARAM)&wallpaper_hwnd);
    return wallpaper_hwnd;
}
#else 
Window get_wallpaper_window(){
    Display* x11d = XOpenDisplay(NULL);
    Window x11w = RootWindow(x11d, DefaultScreen(x11d));
    return x11w;
}
#endif

UI::UI(){
    //no func now
}

int UI::init(bool fullscreen){
    int flag = 0;
    this -> w = parseJSON::w;
    this -> h = parseJSON::h;
    
    if(fullscreen){
        flag = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_VIDEO) == 0){
        SDL_Window* window = SDL_CreateWindowFrom((void*)get_wallpaper_window());
        renderer = SDL_CreateRenderer(window, -1, 0);
    }

    if(parseJSON::fileExtension == "png" || parseJSON::fileExtension == "jpeg"){
        showImage(parseJSON::wallpaperDir)
    }
}

void UI::showImage(SDL_Window* window, string wallpaperDir){
    wallpaperDir = parseJSON::wallpaperDir;
    bool quit = false;
    window

    while(!quit){
        SDL_WaitEvent(&event);

        switch(event.type){
            case SDL_QUIT:
            quit = true;
            break;
        }
    }

    /*
     --todo--
     1. parsing JSON
     2. decide how to organize a wallpaper folder
     */
}