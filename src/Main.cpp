#include <SDL2/SDL.h>
#include <iostream>

#include "../include/Window.hpp"

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main()
{
    std::cout << "Hello, Hydrangea!\n";

    Window *myWindow = new Window(SCREEN_HEIGHT,SCREEN_WIDTH, "Hello, Hydrangea!");

    // Start up SDL and create window
    if (!myWindow->Init())
    {
        printf("[Error] Failed to initialize window!\n");
    }
    else
    {
        bool isRunning = true;
        SDL_Event e;

        while (isRunning)
        {
            // Handle events on queue
            while (SDL_PollEvent(&e) != 0)
            {
                // User presses the X button
                if (e.type == SDL_QUIT)
                {
                    isRunning = false;
                }
                // User presses the Escape key
                else if (e.type == SDL_KEYDOWN)
                {
                    if (e.key.keysym.sym == SDLK_ESCAPE)
                    {
                        isRunning = false;
                    }
                }
            }
        }

        myWindow->Close();
    }

    return 0;
}
