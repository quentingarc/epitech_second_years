/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-teo.martos
** File description:
** Players
*/

#ifndef PLAYERS_HPP_
#define PLAYERS_HPP_

#include <iostream>
#include <memory>
#include "../include/Win.hpp"
#include "raylib.h"

typedef struct player1_s {
    Texture2D player;
    Rectangle rec;
    Vector2 player_pos;
}player1_t;

typedef struct player2_s {
    Texture2D player;
    Rectangle rec;
    Vector2 player_pos;
}player2_t;

typedef struct explo_s
{
    Vector2 bomb_pos;
}explo_t;


typedef struct players_s {
    std::unique_ptr<player1_t> player1;
    std::unique_ptr<player2_t> player2;
    std::unique_ptr<explo_t> explo;
    std::unique_ptr<Win> win;
}players_t;

class Players {
    public:
        Players();
        ~Players();
        void initStructs();
        void loadResources();
        void unloadTextures();
        void AnimBomb();
        void AnimBomb2();
        void AnimCross();
        void AnimCross2();
        bool Player1Movements();
        bool Player2Movements();
        int PlayersAnimation();
    protected:
    private:
        std::unique_ptr<players_t> players;
        Texture2D boom_anim;
        Rectangle boom_anim_bounds;
        Texture2D cross_anim;
        Rectangle cross_anim_bounds;
        int currentFrameBomb;
        int framesCounterBomb;
        int currentFrameCross;
        int framesCounterCross;
        int framesCounter;
        int currentFrame;
};

#endif /* !PLAYERS_HPP_ */
