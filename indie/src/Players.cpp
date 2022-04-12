/*
** EPITECH PROJECT, 2021
** B-YEP-400-BDX-4-1-indiestudio-teo.martos
** File description:
** Players
*/

#include "../include/Players.hpp"

Players::Players()
{
    initStructs();
}

void Players::initStructs()
{
    this->players = std::make_unique<players_t>();
    this->players->player1 = std::make_unique<player1_t>();
    this->players->player2 = std::make_unique<player2_t>();
    this->players->explo = std::make_unique<explo_t>();
    this->players->win = std::make_unique<Win>();
    loadResources();
}

void Players::loadResources()
{
    this->players->player1->player = LoadTexture("resources/player.png");
    this->players->player1->rec = {0.0f, 0.0f, (float)this->players->player1->player.width / 2, (float)this->players->player1->player.height / 5};
    this->players->player1->player_pos = {340.0f, 260.0f};

    this->players->player2->player = LoadTexture("resources/player2.png");
    this->players->player2->rec = {0.0f, 0.0f, (float)this->players->player2->player.width / 2, (float)this->players->player2->player.height / 5};
    this->players->player2->player_pos ={1650.0f, 730.0f};

    this->boom_anim = LoadTexture("resources/bomb.png");
    this->boom_anim_bounds = {0.0f, 0.0f, (float)this->boom_anim.width / 3, (float)this->boom_anim.height};

    this->cross_anim = LoadTexture("resources/cross.png");
    this->cross_anim_bounds = {0.0f, 0.0f, (float)this->cross_anim.width / 4, (float)this->cross_anim.height};

    this->framesCounter = 0;
    this->currentFrame = 0;
    this->framesCounterBomb = 0;
    this->currentFrameBomb = 0;
}

void Players::AnimBomb()
{
    this->framesCounterBomb++;
    if (this->framesCounterBomb >= (60 / 3)) {
        this->framesCounterBomb = 0;
        this->currentFrameBomb++;
        if (this->currentFrameBomb > 2)
            this->currentFrameBomb = 0;
        this->boom_anim_bounds.x = (float)this->currentFrameBomb * (float)this->boom_anim.width / 3;
    }
    DrawTextureRec(this->boom_anim, this->boom_anim_bounds, {this->players->player1->player_pos.x + 10, this->players->player1->player_pos.y + 20}, WHITE);
    AnimCross();
}

void Players::AnimBomb2()
{
    this->framesCounterBomb++;
    if (this->framesCounterBomb >= (60 / 3)) {
        this->framesCounterBomb = 0;
        this->currentFrameBomb++;
        if (this->currentFrameBomb > 2)
            this->currentFrameBomb = 0;
        this->boom_anim_bounds.x = (float)this->currentFrameBomb * (float)this->boom_anim.width / 3;
    }
    DrawTextureRec(this->boom_anim, this->boom_anim_bounds, {this->players->player2->player_pos.x + 10, this->players->player2->player_pos.y + 20}, WHITE);
}

void Players::AnimCross()
{
    this->framesCounterCross++;
    if (this->framesCounterCross >= (60 / 4)) {
        this->framesCounterCross = 0;
        this->currentFrameCross++;
        if (this->currentFrameCross > 3)
            this->currentFrameCross = 0;
        this->cross_anim_bounds.x = (float)this->currentFrameCross * (float)this->cross_anim.width / 4;
    }
    DrawTextureRec(this->cross_anim, this->cross_anim_bounds, {this->players->player1->player_pos.x - 60, this->players->player1->player_pos.y - 60}, WHITE);
}

int Players::PlayersAnimation()
{
    this->framesCounter++;
    if (this->framesCounter >= (60 / 2)) {
        this->framesCounter = 0;
        this->currentFrame++;
        if (this->currentFrame > 1)
            this->currentFrame = 0;
        this->players->player1->rec.x = (float)currentFrame * (float)this->players->player1->player.width / 2;
        this->players->player1->rec.y = 4 * (float)this->players->player1->player.height / 5;
        this->players->player2->rec.x  = (float)currentFrame * (float)this->players->player2->player.width / 2;
        this->players->player2->rec.y = 4 * (float)this->players->player2->player.height / 5;
    }
    if (Player1Movements()) {
        AnimBomb();
        return (1);
    }
    if (Player2Movements()) {
        AnimBomb2();
        return (2);
    }
    return (0);
}

bool Players::Player1Movements()
{
    if (IsKeyDown(KEY_RIGHT)) {
        this->players->player1->rec.y = 1 * (float)this->players->player1->player.height / 5;
        this->players->player1->player_pos.x += 2.0;
    }
    if (IsKeyDown(KEY_LEFT)) {
        this->players->player1->rec.y = 0 * (float)this->players->player1->player.height / 5;
        this->players->player1->player_pos.x -= 2.0;
    }
    if (IsKeyDown(KEY_UP)) {
        this->players->player1->rec.y = 3 *  (float)this->players->player1->player.height / 5;
        this->players->player1->player_pos.y -= 2.0;
    }
    if (IsKeyDown(KEY_DOWN)) {
        this->players->player1->rec.y = 2 * (float)this->players->player1->player.height / 5;
        this->players->player1->player_pos.y += 2.0;
    }
    DrawTextureRec(this->players->player1->player, this->players->player1->rec, this->players->player1->player_pos, WHITE);
    if (IsKeyDown(KEY_E))
        return (true);
    return false;
}

bool Players::Player2Movements()
{
    if (IsKeyDown(KEY_D)) {
        this->players->player2->rec.y = 1 * (float)this->players->player2->player.height / 5;
        this->players->player2->player_pos.x  +=  2.0;
    }
    if (IsKeyDown(KEY_A)) {
        this->players->player2->rec.y = 0 * (float)this->players->player2->player.height / 5;
        this->players->player2->player_pos.x -=  2.0;
    }
    if (IsKeyDown(KEY_W)) {
        this->players->player2->rec.y = 3 *  (float)this->players->player2->player.height / 5;
        this->players->player2->player_pos.y -=  2.0;
    }
    if (IsKeyDown(KEY_S)) {
        this->players->player2->rec.y = 2 * (float)this->players->player2->player.height / 5;
        this->players->player2->player_pos.y  +=  2.0;
    }
    DrawTextureRec(this->players->player2->player, this->players->player2->rec, this->players->player2->player_pos, WHITE);
    if (IsKeyDown(KEY_F))
        return true;
    return false;
}

void Players::unloadTextures()
{
    UnloadTexture(this->players->player1->player);
    UnloadTexture(this->players->player2->player);
}

Players::~Players()
{
}
