#include <SDL2/SDL.h>
#include <cstring>
#include "../include/Window.hpp"

Window::Window(int heightIn, int widthIn, std::string titleIn)
{
    height = heightIn;
    width = widthIn;
    title = titleIn;
}

bool Window::Init()
{
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        // Create window
        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

        if (window == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            // Get window surface
            screenSurface = SDL_GetWindowSurface(window);
        }
    }

    return success;
}


void Window::Close()
{
    // Deallocate any surfaces we have

    //Destroy window
    SDL_DestroyWindow(window);
    window = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}