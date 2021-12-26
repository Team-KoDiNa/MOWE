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

int UI::init(bool fullscreen,string fileDir){
    int flag = 0;
    parseJSON Jsonfile;
    Jsonfile.read_json(fileDir);

    this -> w = Jsonfile.returnWeight();
    this -> h = Jsonfile.returnHeight();
    
    if(fullscreen){
        flag = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_VIDEO) == 0){
        SDL_Window* window = SDL_CreateWindowFrom((void*)get_wallpaper_window());
        renderer = SDL_CreateRenderer(window, -1, 0);
    }

    string fileExt = Jsonfile.returnFileExtension();

    if(fileExt == "png" || fileExt == "jpeg"){ 
        SDL_Surface * image = IMG_Load(Jsonfile.returnWallpaperDir().c_str());
        texture = SDL_CreateTextureFromSurface(renderer, image);
        SDL_FreeSurface(image);
        SDL_Rect destination;
        destination.h = h;
        destination.w = w;
        destination.x = 0;
        destination.y = 0;

        if(SDL_RenderCopy(renderer, texture, NULL, &destination) != 0){
            perror("Rendering ERROR... Quitting . . .");
            clean();
        }
    }
    else if(fileExt == "mp4" || fileExt == "avi"){
        
    }
    
    return 0;
}

void UI::clean(){
    SDL_DestroyWindow(window);
	  SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
	  SDL_Quit();
}

    

