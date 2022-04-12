/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-teo.martos
** File description:
** GameIntroduction
*/

#ifndef SPLASH_SCREEN_HPP_
#define SPLASH_SCREEN_HPP_

#include <iostream>
#include <memory>
#include "raylib.h"

typedef struct back_s {
    Texture2D back;
    Vector2 back_pos;
} back_t;

typedef struct perso_s {
    Texture2D perso;
    Vector2 perso_pos;
} perso_t;

typedef struct musical_s {
    Music music;
    bool pause;
}musical_t;

typedef struct GameIntroduction_s {
    std::unique_ptr<back_t> background;
    std::unique_ptr<perso_t> personnage;    
    std::unique_ptr<musical_t> music;    
} GI_t;

class GameIntroduction {
    public:
        GameIntroduction();
        ~GameIntroduction();
        int drawResources();
        void unloadTextures();
        void next_windows();
        void initStructs();
        int buttonClickHandler();
        void loadResources();
        void initVariables();
        int mainLoop();
    protected:
    private:
        std::unique_ptr<GI_t> splash;

};

#endif /* !SPLASH_SCREEN_HPP_ */