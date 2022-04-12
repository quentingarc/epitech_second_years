/*
** EPITECH PROJECT, 2020
** B-YEP-400-BDX-4-1-indiestudio-teo.martos
** File description:
** GameIntroduction.cpp
*/

#include "../include/GameIntroduction.hpp"

GameIntroduction::GameIntroduction()
{
    initStructs();
}

void GameIntroduction::initStructs()
{
    this->splash = std::make_unique<GI_t>();
    this->splash->background = std::make_unique<back_t>();
    this->splash-> music = std::make_unique<musical_t>();
    loadResources();    
}

void GameIntroduction::loadResources()
{
    this->splash->background->back = LoadTexture("resources/background.png");
    this->splash->music->music = LoadMusicStream("resources/splash_music.wav");
    initVariables();
}

void GameIntroduction::initVariables()
{
    this->splash->music->pause = true;
    PlayMusicStream(this->splash->music->music);
}

int GameIntroduction::buttonClickHandler()
{
    if (IsKeyPressed(KEY_SPACE))
            return (1);
    return (0);
}

int GameIntroduction::drawResources()
{
    ClearBackground(BLACK);
    UpdateMusicStream(this->splash->music->music);

    DrawTexture(this->splash->background->back, 0, 0, WHITE);
    DrawText("[ PRESS SPACE TO CONTINUE ]", 200, 650, 60, WHITE);
    if (buttonClickHandler() == 1)
        return (1);
    return (0);
}

void GameIntroduction::unloadTextures()
{
    UnloadTexture(this->splash->background->back);
    UnloadMusicStream(this->splash->music->music);
}

GameIntroduction::~GameIntroduction()
{
}