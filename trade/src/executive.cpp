/*
** EPITECH PROJECT, 2021
** B-CNA-410-BDX-4-1-trade-sergiu.hincu
** File description:
** executive
*/

#include "trade.hpp"

int Trade::executive(std::vector<std::string> separate)
{
    if(separate.empty())
        return 84;
    if (std::strcmp(separate[0].c_str(), "settings") == 0)
        return 1;
    if (std::strcmp(separate[0].c_str(), "update") == 0)
        return 2;
    if (std::strcmp(separate[0].c_str(), "action") == 0)
        return 3;
    else
        return 84;
}

int Trade::executive_settings(std::vector<std::string> separate)
{ 
    if (std::strcmp(separate[1].c_str(), "player_names") == 0)
        return 0;
    if (std::strcmp(separate[1].c_str(), "your_bot") == 0)
        return 1;
    if (std::strcmp(separate[1].c_str(), "timebank") == 0)
        return 2;
    if (std::strcmp(separate[1].c_str(), "time_per_move") == 0)
        return 3;
    if (std::strcmp(separate[1].c_str(), "candle_interval") == 0)
        return 4;
    if (std::strcmp(separate[1].c_str(), "candle_format") == 0)
        return 5;
    if (std::strcmp(separate[1].c_str(), "candles_total") == 0)
        return 6;
    if (std::strcmp(separate[1].c_str(), "candles_given") == 0)
        return 7;
    if (std::strcmp(separate[1].c_str(), "initial_stack") == 0)
        return 8;
    if (std::strcmp(separate[1].c_str(), "transaction_fee_percent") == 0)
        return 9;
    else
        return 84;
}

int Trade::executive_update(std::vector<std::string> separate)
{
    if (std::strcmp(separate[2].c_str(), "next_candles"))
        return 0;
    if (std::strcmp(separate[2].c_str(), "stacks"))
        return 1;
    else
        return 84;
}