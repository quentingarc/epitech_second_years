/*
** EPITECH PROJECT, 2021
** B-CNA-410-BDX-4-1-trade-sergiu.hincu
** File description:
** trade
*/

#include "trade.hpp"

Trade::Trade(void) {}

Trade::~Trade(void) {}


std::vector<std::string> string_to_vector(std::string s, char c)
{
    std::string temp = "";
    std::vector<std::string> v;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == c)
        {
            v.push_back(temp);
            temp = "";
        }
        else
        {
            temp.push_back(s[i]);
        }
    }
    v.push_back(temp);
    return (v);
}

void Trade::mannagment(void)
{
    for (std::string line; std::getline(std::cin, line);)
    {
        std::vector<std::string> separate = string_to_vector(line, ' ');
            switch (int exec = this->executive(separate))
            {
            case 1:
                this->settings(separate);
                break;
            case 2:
            std::cerr << exec << std::endl;
                this->update(separate);
                break;
            case 3:
                this->mannagment_trade(separate);
                break;
            default :
                break;
            }
    }
}