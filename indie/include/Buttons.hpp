/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-teo.martos
** File description:
** Buttons
*/

#ifndef BUTTONS_HPP_
#define BUTTONS_HPP_

#include <iostream>
#include <memory>
#include "raylib.h"

class Buttons {
    public:
        Buttons();
        ~Buttons();
        void setTextures(std::string);
        void setDoubleTextures(std::string, std::string);
        void setPositions(float, float, float, float);
        int getTextureWidth();
        int getTextureHeight();
        bool getAction();
        void drawTextures(int, int, Color);
        void drawDoubleTextures(int, int, Color);
        void unloadTextures();
        void unloadDoubleTextures();
        void normalButtonHandler();
        int clickButtonHandler();

    protected:
    private:
    Texture2D untouched;
    Texture2D touched;
    Rectangle rectangle;
    Rectangle bounds;
    bool action;
};

#endif /* !BUTTONS_HPP_ */
