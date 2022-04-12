/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-teo.martos
** File description:
** Epitech
*/

#ifndef EPITECH_HPP_
#define EPITECH_HPP_

#include <iostream>
#include <memory>
#include "raylib.h"

typedef struct logo_s {
    Texture2D logo_tech;
    Vector2 logo_pos;
} logo_t;

typedef struct epitech_s {
    std::unique_ptr<logo_t> logo;
} epitech_t;

class Epitech {
    public:
        Epitech();
        ~Epitech();
        int drawResources();
        void unloadTextures();
        void next_windows();
        void initStructs();
        int mainLoop();
        int buttonClickHandler();
        void loadResources();
        void initVariables();
    protected:
    private:
        std::unique_ptr<epitech_t> epitech;
};

#endif /* !EPITECH_HPP_ */
