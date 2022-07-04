#include <iostream>
#include <strings.h>

#ifndef WINDOW_H
#define WINDOW_H

class Window
{
private:
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;
    int height = 480;
    int width = 640;
    std::string title = "Hydrangea";

public:
    Window(int heightIn, int widthIn, std::string titleIn);
    bool Init();
    void Close();
    SDL_Window *getWindow();
    SDL_Surface *getSurface();
    int getWidth();
    int getHeight();
};

#endif