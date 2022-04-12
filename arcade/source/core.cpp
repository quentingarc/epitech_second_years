/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-quentin.garcia
** File description:
** arcade
*/

#include "core.hpp"
#include <iostream>

Core::Core(int ac, char **av)
{
    this->core_error(ac, av);
}

Core::~Core()
{
    delete this->_weigh;
    delete this->_graphic;
}

void Core::print_error()
{
    std::cout << "USAGE not good implemenration" << std::endl;
    std::cout << "./arcade ./libs/arcade_ncurses.so" << std::endl;
}
void Core::core_error(int ac, char **av)
{
    if (ac == 2)
        this->print_error();
    this->_weigh = new weigh("./libs/", "./games/");
    this->_graphics = this->_weigh->getGraph();
    this->_graphic = this->List_Language(av[1]);

    
}

Graphic::Languages *Core::List_Language(const std::string &path)
{
    Graphic::Languages *(*create)();
    Graphic::Languages *graphic = nullptr;

    this->_graphic_stock = dlopen(path.c_str(), RTLD_LAZY);
    if (this->_graphic_stock == nullptr)
        std::cerr << dlerror() << std::endl;
    create = (Graphic::Languages * (*)()) dlsym(this->_graphic_stock, "createGraphic");
    graphic = (*create)();
    return graphic;
}