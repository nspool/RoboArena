//
//  Player.cpp
//  RoboChase
//
//  Created by nsp on 2/6/17.
//  Copyright © 2017 nspool. All rights reserved.
//

#include <SDL_image.h>

#include "player.hpp"

Player::Player(SDL_Point initialPosition)
{
    // Load the player sprite
    SDL_Surface* gPlayer = IMG_Load("player.png");
    if(gPlayer == 0)
    {
        SDL_LogError(0, "%s", SDL_GetError());
        return;
    }

    position = initialPosition;
}
