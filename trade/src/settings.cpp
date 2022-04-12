/*
** EPITECH PROJECT, 2021
** B-CNA-410-BDX-4-1-trade-sergiu.hincu
** File description:
** settings
*/

#include "trade.hpp"

void Trade::settings(std::vector<std::string> separate)
{
    switch (int exec = executive_settings(separate))
    {
        case 0 :
            this->_settings.player_names = separate[2].c_str();
            break;
        case 1 :
            this->_settings.your_bot = separate[2].c_str();
            break;
        case 2 :
            this->_settings.timebank = std::atoi(separate[2].c_str());
            break;
        case 3 : 
            this->_settings.time_per_move = std::atoi(separate[2].c_str());
            break;
        case 4 :
            this->_settings.candle_interval = std::atoi(separate[2].c_str());
            break;
        case 5 :
            this->_settings.candle_format = separate[2].c_str();
            break;
        case 6 :
            this->_settings.candles_total = std::atoi(separate[2].c_str());
            break;
        case 7 :
            this->_settings.candles_given = std::atoi(separate[2].c_str());
            break;
        case 8 :
            this->_settings.initial_stack = std::atoi(separate[2].c_str());
            break;
        case 9 :
            this->_settings.transaction_fee_percent = std::atof(separate[2].c_str());
            break;
        default :
            break;
    }
}