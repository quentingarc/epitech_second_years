/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-quentin.garcia
** File description:
** weigh
*/

#ifndef WEIGH_HPP
#define WEIGH_HPP
#include <string>
#include <cstring>
#include <vector>
#include <dirent.h>

class weigh
{
public:
    weigh(const std::string &lib, const std::string &games);
    ~weigh();
    std::vector<std::string> getGraph() const;
    std::vector<std::string> getGame() const;

private:
    std::vector<std::string> _Graph;
    std::vector<std::string> _Game;
    std::vector<std::string> Dir(std::vector<std::string> tab,
    const std::string &path);
};

#endif