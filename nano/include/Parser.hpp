/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>

class Parser {
    public:
        Parser();
        ~Parser();

        bool check_file_name(std::string);
        std::vector<std::string> get_file_content(std::string);
        void print_vector(std::vector<std::string>);
        bool check_chipsets(std::vector<std::string>);
        bool check_links(std::vector<std::string>);
        size_t get_pos(std::string, std::vector<std::string>);
        std::vector<std::string> get_chipsets(std::string);
        std::vector<std::string> get_links(std::string);
    protected:
    private:
};

#endif /* !PARSER_HPP_ */
 