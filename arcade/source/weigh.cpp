/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-quentin.garcia
** File description:
** weigh
*/

#include "weigh.hpp"
#include <iostream>

weigh::weigh(const std::string &lib, const std::string &games)
{
    this->_Game = Dir(this->_Game, games);
    this->_Graph = Dir(this->_Graph, lib);
}

weigh::~weigh() {}

std::vector<std::string> weigh::Dir(std::vector<std::string> tab, const std::string &type)
{
    DIR *stream = opendir(type.c_str());
    struct dirent *folder = nullptr;

    if (stream == nullptr)
      std::cout << "Rather the ./games/ or the ./lib/ directory wasn't found." << std::endl;
    folder = readdir(stream);
    while (folder != nullptr)
    {

        if (folder->d_name[strlen(folder->d_name) - 2] == 's' &&
            folder->d_name[strlen(folder->d_name) - 1] == 'o' &&
            folder->d_name[strlen(folder->d_name) - 3] == '.')
            tab.push_back(folder->d_name);
        folder = readdir(stream);
    }
    closedir(stream);
    return (tab);
}

std::vector<std::string> weigh::getGraph() const
{
    return (this->_Graph);
}

std::vector<std::string> weigh::getGame() const
{
    return (this->_Game);
}