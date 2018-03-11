//
//  main.cpp
//  RoboaArena
//
//  Created by nspool on 8/3/18.
//  Copyright © 2018 nspool. All rights reserved.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

int WINDOW_WIDTH = 640;
int WINDOW_HEIGHT = 480;

// FIXME: Ugly hack workaround to fix the undefined reference to `WinMain' error on Windows
#ifdef main
# undef main
#endif
int main(int argc, char** argv)
{
  if(SDL_Init(SDL_INIT_TIMER|SDL_INIT_VIDEO) < 0 )
  {
    SDL_Log("Failed to initialise SDL!\n");
    return 1;
  }

  SDL_Window* window = SDL_CreateWindow("RoboArena",
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        WINDOW_WIDTH, WINDOW_HEIGHT,
                                        SDL_WINDOW_SHOWN);
  if(window == 0)
  {
    SDL_Log("SDL_CreateWindow: SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if(renderer == 0)
  {
    SDL_Log("SDL_CreateRenderer: SDL Error: %s\n", SDL_GetError());
    return 1;
  }

  SDL_SetWindowTitle(window, "RoboArena");
  SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

  // Main event loop

  SDL_Event e;
  bool quit = false;

  do {

    if(SDL_PollEvent(&e) != 0)
    {
      if (e.type == SDL_QUIT) {
          quit = true;
      }
    }

    int windowX, windowY, mouseX, mouseY;
    SDL_GetWindowPosition(window, &windowX, &windowY);
    SDL_GetGlobalMouseState(&mouseX, &mouseY);
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0 );
    SDL_RenderClear(renderer);

    SDL_Point mousePoint = {mouseX - windowX, mouseY - windowY};

    SDL_RenderPresent(renderer);

  } while(!quit);

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
