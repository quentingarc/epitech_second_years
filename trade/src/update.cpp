/*
** EPITECH PROJECT, 2021
** B-CNA-410-BDX-4-1-trade-sergiu.hincu
** File description:
** update
*/

#include "trade.hpp"

void Trade::parse_data(std::vector<std::string> separate)
{
    std::vector<std::string> separate_pair = string_to_vector(separate[3].c_str(), ';');
    std::vector<std::string> separate_data_BTC_ETH = string_to_vector(separate_pair[0].c_str(), ',');
    std::vector<std::string> separate_data_USDT_ETH = string_to_vector(separate_pair[1].c_str(), ',');
    std::vector<std::string> separate_data_USDT_BTC = string_to_vector(separate_pair[2].c_str(), ',');

    this->_update.pair_BTC_ETH.push_back(separate_data_BTC_ETH[0].c_str());
    this->_update.date_BTC_ETH.push_back(std::atoi(separate_data_BTC_ETH[1].c_str()));
    this->_update.high_BTC_ETH.push_back(std::atof(separate_data_BTC_ETH[2].c_str()));
    this->_update.low_BTC_ETH.push_back(std::atof(separate_data_BTC_ETH[3].c_str()));
    this->_update.open_BTC_ETH.push_back(std::atof(separate_data_BTC_ETH[4].c_str()));
    this->_update.close_BTC_ETH.push_back(std::atof(separate_data_BTC_ETH[5].c_str()));
    this->_update.volume_BTC_ETH.push_back(std::atof(separate_data_BTC_ETH[6].c_str()));

    this->_update.pair_USDT_ETH.push_back(separate_data_USDT_ETH[0].c_str());
    this->_update.date_USDT_ETH.push_back(std::atoi(separate_data_USDT_ETH[1].c_str()));
    this->_update.high_USDT_ETH.push_back(std::atof(separate_data_USDT_ETH[2].c_str()));
    this->_update.low_USDT_ETH.push_back(std::atof(separate_data_USDT_ETH[3].c_str()));
    this->_update.open_USDT_ETH.push_back(std::atof(separate_data_USDT_ETH[4].c_str()));
    this->_update.close_USDT_ETH.push_back(std::atof(separate_data_USDT_ETH[5].c_str()));
    this->_update.volume_USDT_ETH.push_back(std::atof(separate_data_USDT_ETH[6].c_str()));

    this->_update.pair_USDT_BTC.push_back(separate_data_USDT_BTC[0].c_str());
    this->_update.date_USDT_BTC.push_back(std::atoi(separate_data_USDT_BTC[1].c_str()));
    this->_update.high_USDT_BTC.push_back(std::atof(separate_data_USDT_BTC[2].c_str()));
    this->_update.low_USDT_BTC.push_back(std::atof(separate_data_USDT_BTC[3].c_str()));
    this->_update.open_USDT_BTC.push_back(std::atof(separate_data_USDT_BTC[4].c_str()));
    this->_update.close_USDT_BTC.push_back(std::atof(separate_data_USDT_BTC[5].c_str()));
    this->_update.volume_USDT_BTC.push_back(std::atof(separate_data_USDT_BTC[6].c_str()));
}

void Trade::parse_stacks(std::vector<std::string> separate)
{
    std::vector<std::string> separate_pair = string_to_vector(separate[3].c_str(), ',');
    std::vector<std::string> separate_BTC = string_to_vector(separate_pair[0].c_str(), ':');
    std::vector<std::string> separate_ETH = string_to_vector(separate_pair[1].c_str(), ':');
    std::vector<std::string> separate_USDT = string_to_vector(separate_pair[2].c_str(), ':');

    this->_stacks.BTC.push_back(std::atof(separate_BTC[1].c_str()));
    this->_stacks.ETH.push_back(std::atof(separate_ETH[1].c_str()));
    this->_stacks.USDT.push_back(std::atof(separate_USDT[1].c_str()));
}

void Trade::update(std::vector<std::string> separate)
{
    std::vector<std::string> format = string_to_vector(this->_settings.candle_format, ',');

    if (separate[1] == "game")
    {
        switch (int exec = executive_update(separate))
        {
        case 0:
            parse_data(separate);
            break;
        case 1:
            parse_stacks(separate);
            break;
        default:
            break;
        }
    }
}