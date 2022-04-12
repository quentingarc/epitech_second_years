/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-teo.martos
** File description:
** Epitech
*/

#include "../include/Splash_intro.hpp"

Epitech::Epitech()
{
    initStructs();
}

void Epitech::initStructs()
{
    this->epitech = std::make_unique<epitech_t>();
    this->epitech->logo = std::make_unique<logo_t>();
    loadResources();
}

void Epitech::loadResources()
{
    this->epitech->logo->logo_tech = LoadTexture("resources/epitech.png");
}

int Epitech::buttonClickHandler()
{
    if (GetTime() > 3)
        return (1);
    return (0);
}

int Epitech::drawResources()
{
    ClearBackground(BLACK);
    DrawTexture(this->epitech->logo->logo_tech, 500, 200, WHITE);
    DrawText("B4 - Year-End-Project - Indie Studio", 300, 700, 75, WHITE);
    buttonClickHandler();
    if (buttonClickHandler() == 1)
        return (1);
    return 0;
}

void Epitech::unloadTextures()
{
    UnloadTexture(this->epitech->logo->logo_tech);
}

Epitech::~Epitech()
{
}