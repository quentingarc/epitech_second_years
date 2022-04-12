/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-teo.martos
** File description:
** Buttons
*/

#include "../include/Buttons.hpp"

Buttons::Buttons()
{
}

void Buttons::setTextures(std::string path)
{
    this->untouched = LoadTexture(path.c_str());
}

void Buttons::setDoubleTextures(std::string first_path, std::string second_path)
{
    this->untouched = LoadTexture(first_path.c_str());
    this->touched = LoadTexture(second_path.c_str());
}

void Buttons::setPositions(float x, float y, float width, float height)
{
    this->rectangle = {x, y, width, height};
    this->bounds = {x, y, width, height};
}

void Buttons::drawTextures(int x, int y, Color color)
{
    DrawTexture(this->untouched, x, y, color);
}

void Buttons::drawDoubleTextures(int x, int y, Color color)
{
    normalButtonHandler();
    if (getAction())
        DrawTexture(this->touched, x, y, color);
    else
        DrawTexture(this->untouched, x, y, color);
}

void Buttons::unloadTextures()
{
    UnloadTexture(this->untouched);
}

void Buttons::unloadDoubleTextures()
{
    UnloadTexture(this->untouched);
    UnloadTexture(this->touched);
}

int Buttons::getTextureWidth()
{
    return (this->untouched.width);
}

bool Buttons::getAction()
{
    return (this->action);
}

int Buttons::getTextureHeight()
{
    return (this->untouched.height);
}

void Buttons::normalButtonHandler()
{
    if (CheckCollisionPointRec(GetMousePosition(), this->bounds)) {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) == false)
            this->action = true;
    } else
       this->action = false;
}

int Buttons::clickButtonHandler()
{
    if (CheckCollisionPointRec(GetMousePosition(), this->bounds)) {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) == false)
            this->action = true;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return (1);
    } else
        this->action = false;
    return (0);
}

Buttons::~Buttons()
{
}
