/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-teo.martos
** File description:
** Menu
*/

#include "../include/Menu.hpp"

Menu::Menu()
{
    initStructs();
}

void Menu::initStructs()
{
    this->m = std::make_unique<menu_t>();
    this->m->play = std::make_unique<Buttons>();
    this->m->quit = std::make_unique<Buttons>();
    this->m->help = std::make_unique<Buttons>();
    this->m->background = std::make_unique<background_t>();
    this->m-> music = std::make_unique<music_t>();
    this->m->mouse = std::make_unique<mouse_t>();
    loadResources();    
}

void Menu::loadResources()
{
    this->m->play->setDoubleTextures("resources/start_untouched.png", "resources/start_touched.png");
    this->m->quit->setDoubleTextures("resources/quit_untouched.png", "resources/quit_touched.png");
    this->m->help->setDoubleTextures("resources/help_untouched.png", "resources/help_touched.png");
    this->cmds = LoadTexture("resources/commands.png");
    this->m->background->sky = LoadTexture("resources/sky.png");
    this->m->background->grass = LoadTexture("resources/grass.png");
    this->m->background->clouds = LoadTexture("resources/clouds.png");
    this->m->background->menu_anim = LoadTexture("resources/menu_animation.png");
    this->m->mouse->mouse = LoadTexture("resources/mouse.png");
    this->m->background->logo = LoadTexture("resources/bomberman_logo.png");
    this->m->music->music = LoadMusicStream("resources/sound.wav");
    initVariables();
}

void Menu::initVariables()
{
    this->m->mouse->mouse_pos = {0.0f, 0.0f};
    this->m->play->setPositions(400.0f, 330.0f, (float)this->m->play->getTextureWidth(), (float)this->m->play->getTextureHeight());
    this->m->quit->setPositions(1200.0f, 330.0f, (float)this->m->quit->getTextureWidth(), (float)this->m->quit->getTextureHeight());
    this->m->help->setPositions(800.0f, 330.0f, (float)this->m->help->getTextureWidth(), (float)this->m->help->getTextureHeight());
    this->m->music->pause = true;
    this->m->background->sky_mov = -1920.0f;
    this->m->background->grass_mov = -1920.0f;
    this->m->background->clouds_mov = -1920.0f;
    this->m->background->menu_anim_pos = {1000.0f, 730.0f,};
    this->m->background->menu_anim_bounds = {0.0f, 0.0f, (float)this->m->background->menu_anim.width / 4, (float)this->m->background->menu_anim.height};
    this->m->background->currentFrame = 0;
    this->m->background->framesCounter = 0;
    PlayMusicStream(this->m->music->music);
}

void Menu::getPlayerMenuAnimation()
{
    this->m->background->framesCounter++;
    if (this->m->background->framesCounter >= (60 / 4)) {
        this->m->background->framesCounter = 0;
        this->m->background->currentFrame++;
        if (this->m->background->currentFrame > 3)
            this->m->background->currentFrame = 0;
        this->m->background->menu_anim_bounds.x = (float)this->m->background->currentFrame * (float)this->m->background->menu_anim.width / 4;
    }
    DrawTextureRec(this->m->background->menu_anim, this->m->background->menu_anim_bounds, this->m->background->menu_anim_pos, WHITE);
}

void Menu::getBackgroundtoMove()
{
    this->m->background->sky_mov -= 0.90f;
    this->m->background->grass_mov -= 1.20;
    this->m->background->clouds_mov -= 1.20f;
    if (this->m->background->sky_mov < -1920 || this->m->background->grass_mov < -1920 || this->m->background->clouds_mov < -1920) {
        this->m->background->sky_mov = 0;
        this->m->background->grass_mov = 0;
        this->m->background->clouds_mov = 0;
    }
    DrawTexture(this->m->background->sky, this->m->background->sky_mov, 0, WHITE);
    DrawTexture(this->m->background->grass, this->m->background->grass_mov, 0, WHITE);
    DrawTexture(this->m->background->clouds, this->m->background->clouds_mov, 0, WHITE);
}

Vector2 Menu::getMousePosition()
{
    this->m->mouse->mouse_pos = GetMousePosition();
    return this->m->mouse->mouse_pos;
}

void Menu::addSound()
{
    UpdateMusicStream(this->m->music->music);

    if (IsKeyPressed(KEY_SPACE)) {
        this->m->music->pause = !this->m->music->pause;
        if (this->m->music->pause)
            PauseMusicStream(this->m->music->music);
        else
            ResumeMusicStream(this->m->music->music);
    }
}

int Menu::drawResources()
{
    this->m->mouse->mouse_pos = getMousePosition();
    ClearBackground(BLACK);
    addSound();
    getBackgroundtoMove();
    getPlayerMenuAnimation();
    this->m->play->drawDoubleTextures(400, 330, WHITE);
    this->m->quit->drawDoubleTextures(1200, 330, WHITE);
    this->m->help->drawDoubleTextures(800, 330, WHITE);
    DrawTexture(this->m->background->logo, 500, 0, WHITE);
    DrawTexture(this->m->mouse->mouse, this->m->mouse->mouse_pos.x - 78, this->m->mouse->mouse_pos.y - 45, WHITE);
    if (this->m->quit->clickButtonHandler() == 1)
        return (1);
    else if (this->m->play->clickButtonHandler() == 1)
        return (2);
    else if (this->m->help->clickButtonHandler() == 1)
        return (3);
    return (0);
}

void Menu::drawCommands()
{
    ClearBackground(BLACK);
    DrawTexture(this->cmds, 0.0f, 0.0f, WHITE);
}

void Menu::unloadTextures()
{
    this->m->play->unloadDoubleTextures();
    this->m->quit->unloadDoubleTextures();
    this->m->help->unloadDoubleTextures();
    UnloadTexture(this->m->background->sky);
    UnloadTexture(this->m->background->grass);
    UnloadTexture(this->m->background->clouds);
    UnloadTexture(this->m->background->menu_anim);
    UnloadTexture(this->m->background->logo);
    UnloadTexture(this->m->mouse->mouse);
    UnloadMusicStream(this->m->music->music);
}

Menu::~Menu()
{
}
