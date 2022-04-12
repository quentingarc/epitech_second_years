/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-teo.martos
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <iostream>
#include <memory>
#include "raylib.h"
#include "../include/Players.hpp"

typedef struct camera_s {
    Camera cam;
    Mesh mesh;
    Model model;
} camera_t;

typedef struct texture_s {
    Image map;
    Texture2D cubicmap;
    Texture2D atlas;
    Vector3 mapPosition;
} texture_t;

typedef struct map_s {
    std::unique_ptr<camera_t> camera;
    std::unique_ptr<texture_t> textures;
} map_t;

class Map {
    public:
        Map();
        ~Map();
        void initStructs();
        void drawResources();
        void unloadTextures();
        void loadResources();
        Camera getCamera();

    protected:
    private:
        std::unique_ptr<map_t> map;
};

#endif /* !MAP_HPP_ */
