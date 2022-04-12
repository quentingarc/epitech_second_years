/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-quentin.garcia
** File description:
** core
*/

#ifndef CORE_HPP_
#define CORE_HPP_
#include <dlfcn.h>
#include <unistd.h>
#include <ctime>
#include <cstring>
#include <memory>
#include "weigh.hpp"
#include "graphic.hpp"


class Core
{
public:
    Core(int ac, char **av);
    ~Core();
    std::vector<std::string> getGraph() const;
    std::vector<std::string> getGame() const;

private:
    void core_error(int ac, char **av);
    void print_error();

private:
    weigh *_weigh;
    std::vector<std::string> _graphics;
    Graphic::Languages *List_Language(const std::string &path);
    Graphic::Languages *_graphic;
    void *_graphic_stock;
};

#endif