/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-teo.martos
** File description:
** Win
*/

#include "../include/Win.hpp"

Win::Win()
{
    loadResources();
}

void Win::loadResources()
{
    this->win1 = LoadTexture("resources/player1win.png");
    this->win2 = LoadTexture("resources/player2win.png");
}

void Win::drawPlayer1()
{
    ClearBackground(BLACK);
    DrawTexture(this->win1, 500, 200, WHITE);

}

void Win::drawPlayer2()
{
    ClearBackground(BLACK);
    DrawTexture(this->win2, 500, 200, WHITE);
}

void Win::unloadTextures()
{
    UnloadTexture(this->win1);
    UnloadTexture(this->win2);
}

Win::~Win()
{
}
