/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser()
{
}

void Parser::print_vector(std::vector<std::string> content)
{
    std::vector<std::string>::iterator i = content.begin();

    for (; i < content.end(); i++)
        std::cout << *i << std::endl;
}

bool Parser::check_file_name(std::string file_name)
{
    std::string check = file_name.substr(file_name.size() - 4, 4);

    if (check == ".nts")
        return (true);
    return (false);
}

bool Parser::check_chipsets(std::vector<std::string> content)
{
    std::vector<std::string>::iterator i = content.begin();

    for (; i < content.end(); i++) {
        if (*i == ".chipsets:")
            return (true);
    }
    return (false);
}

bool Parser::check_links(std::vector<std::string> content)
{
    std::vector<std::string>::iterator i = content.begin();

    for (; i < content.end(); i++) {
        if (*i == ".links:")
            return (true);
    }
    return (false);
}

std::vector<std::string> Parser::get_file_content(std::string file_name)
{
    std::vector<std::string> content;
    std::string stock;
    std::fstream file(file_name);

    if (file.is_open() == true) {
        while (std::getline(file, stock))
            content.push_back(stock);
    }
    return (content);
}

size_t Parser::get_pos(std::string look_for, std::vector<std::string> content)
{
    int inc = 0;
    std::vector<std::string>::iterator i = content.begin();

    for (; i < content.end(); i++, inc++) {
        if (*i == look_for)
            return (inc + 1);
    }
    return (84);
}

std::vector<std::string> Parser::get_chipsets(std::string file_name)
{
    std::vector<std::string> content = get_file_content(file_name);
    std::vector<std::string> chipsets;
    size_t inc = get_pos(".chipsets:", content);

    while (content[inc] != ".links:") {
        chipsets.push_back(content[inc]);
        inc++;
    }
    chipsets.pop_back();
    return (chipsets);
}

std::vector<std::string> Parser::get_links(std::string file_name)
{
    std::vector<std::string> content = get_file_content(file_name);
    std::vector<std::string> links;
    size_t inc = get_pos(".links:", content);

    while (inc < content.size()) {
        links.push_back(content[inc]);
        inc++;
    }
    return (links);

}

Parser::~Parser()
{
}