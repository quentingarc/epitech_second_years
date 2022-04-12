/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-teo.martos
** File description:
** main
*/

#include "include/Menu.hpp"
#include "include/GameIntroduction.hpp"
#include "include/Splash_intro.hpp"
#include "include/Map.hpp"
#include "raylib.h"

int main(void)
{
    InitWindow(1920, 1080, "Game Screen");
    HideCursor();
    SetTargetFPS(60);
    InitAudioDevice();

    GameIntroduction gi;
    Menu m;
    Epitech splash;
    Map map;
    Players p;
    Win w;
    int gameScenes = 0;
    int value = 0;

   while (!WindowShouldClose()) {
        BeginDrawing();
            if (gameScenes == 0) {
                value = splash.drawResources();
                if (value == 1)
                    gameScenes = 1;
            }
            if (gameScenes == 1) {
                value = gi.drawResources();
                if (value == 1)
                    gameScenes = 2;
            }
            if (gameScenes == 2) {
                value = m.drawResources();
                if (value == 1) {
                    break;
                } else if (value == 2)
                    gameScenes = 3;
                else if (value == 3)
                    gameScenes = 6;
            }
            if (gameScenes == 3) {
                BeginMode3D(map.getCamera());
                    map.drawResources();
                EndMode3D();
                value = p.PlayersAnimation();
                if (value == 1)
                    gameScenes = 4;
                else if (value == 2)
                    gameScenes = 5;
            }
            if (gameScenes == 4) {
                w.drawPlayer1();
                if (IsKeyPressed(KEY_SPACE)) {
                    gameScenes = 2;
                }
            }
            else if (gameScenes == 5) {
                w.drawPlayer2();
                if (IsKeyPressed(KEY_SPACE)) {
                    gameScenes = 2;
                }
            }
            if (gameScenes == 6) {
                m.drawCommands();
                if (IsKeyPressed(KEY_SPACE))
                    gameScenes = 2;
            }
        EndDrawing();
    }
    m.unloadTextures();
    gi.unloadTextures();
    splash.unloadTextures();
    map.unloadTextures();
    p.unloadTextures();
    w.unloadTextures();
    CloseWindow();
    CloseAudioDevice(); 
    return (0);
}