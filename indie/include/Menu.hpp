/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-teo.martos
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <iostream>
#include <memory>
#include "Buttons.hpp"
#include "raylib.h"

typedef struct background_s {
    Texture2D sky;
    Texture2D grass;
    Texture2D clouds;
    Texture2D logo;
    Texture2D menu_anim;
    Vector2 sky_pos;
    Vector2 grass_pos;
    Vector2 clouds_pos;
    float sky_mov;
    float grass_mov;
    float clouds_mov;
    Rectangle menu_anim_bounds;
    Vector2 menu_anim_pos;
    int currentFrame;
    float framesCounter;
} background_t;

typedef struct mouse_s {
    Texture2D mouse;
    Vector2 mouse_pos;
}mouse_t;

typedef struct music_s {
    Music music;
    bool pause;
}music_t;

typedef struct menu_s {
    std::unique_ptr<Buttons> play;
    std::unique_ptr<Buttons> quit;
    std::unique_ptr<Buttons> help;
    std::unique_ptr<background_t> background;    
    std::unique_ptr<music_t> music;    
    std::unique_ptr<mouse_t> mouse;
} menu_t;

class Menu {
    public:
        Menu();
        ~Menu();
        Vector2 getMousePosition();
        void unloadTextures();
        void loadResources();
        int drawResources();
        void addSound();
        void initStructs();
        void getBackgroundtoMove();
        void getPlayerMenuAnimation();
        void initVariables();
        void drawCommands();
    protected:
    private:
        std::unique_ptr<menu_t> m;
        Texture2D cmds;
};

#endif /* !MENU_HPP_ */
