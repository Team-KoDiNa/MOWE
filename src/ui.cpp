#include "header/ui.h"

#if Win32
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
void* get_wallpaper_window(int argc, char * argv[]){
    GtkWidget *widget;
    gtk_init (&argc, &argv);
    Window w = gdk_x11_drawable_get_xid(gtk_widget_get_window(widget));
    return w;
}
#endif

UI::UI(){
    //no func now
}

int UI::init(const char *title, int w, int h, bool fullscreen){
    int flag = 0;
    this -> w = w;
    this -> h = h;
    
    if(fullscreen){
        flag = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_VIDEO) == 0){
        window = SDL_CreateWindowFrom((void*)get_wallpaper_window());
    }
    
}
