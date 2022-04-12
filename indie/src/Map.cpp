/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-teo.martos
** File description:
** Map
*/

#include "../include/Map.hpp"

Map::Map()
{
    initStructs();
}

void Map::initStructs()
{
    this->map = std::make_unique<map_t>();
    this->map->camera = std::make_unique<camera_t>();
    this->map->textures = std::make_unique<texture_t>();
    loadResources();
}

void Map::loadResources()
{
    this->map->camera->cam = {{0.0f, 24.0f, 16.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, 45.0f, 0};
    this->map->textures->map = LoadImage("resources/test.png");
    this->map->textures->cubicmap = LoadTextureFromImage(this->map->textures->map);
    this->map->camera->mesh = GenMeshCubicmap(this->map->textures->map, Vector3{1.0f, 1.0f, 1.0f});
    this->map->camera->model = LoadModelFromMesh(this->map->camera->mesh);
    this->map->textures->atlas = LoadTexture("resources/cubicmap_atlas.png");
    this->map->camera->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->map->textures->atlas;
    this->map->textures->mapPosition = { -16.0f, 0.0f, -8.0f };
    UnloadImage(this->map->textures->map);     
}

void Map::drawResources()
{
    ClearBackground(BLACK);
    UpdateCamera(&this->map->camera->cam); 
    DrawModel(this->map->camera->model, this->map->textures->mapPosition, 1.0f, WHITE);
}

void Map::unloadTextures()
{
    UnloadTexture(this->map->textures->cubicmap);    
    UnloadTexture(this->map->textures->atlas);     
    UnloadModel(this->map->camera->model);
}

Camera Map::getCamera()
{
    return (this->map->camera->cam);
}

Map::~Map()
{
}
