/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-teo.martos
** File description:
** Win
*/

#ifndef WIN_HPP_
#define WIN_HPP_

#include <iostream>
#include <memory>
#include "raylib.h"

class Win {
    public:
        Win();
        ~Win();
        void unloadTextures();
        void drawResources();
        void loadResources();
        void drawPlayer1();
        void drawPlayer2();
    protected:
    private:
        Texture2D win1;
        Texture2D win2;
};

#endif /* !WIN_HPP_ */
