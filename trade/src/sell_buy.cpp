/*
** EPITECH PROJECT, 2021
** B-CNA-410-BDX-4-1-trade-sergiu.hincu
** File description:
** sell_buy
*/

#include "trade.hpp"

void Trade::pass()
{
    std::cout << "pass" << std::endl;
}

void Trade::mannagment_trade(std::vector<std::string> separate)
{
    if(this->_stacks.USDT.size() != 0 && this->_update.open_BTC_ETH < this->_update.close_BTC_ETH)
        std::cout << "buy BTC_ETH 20" << std::endl;
    else if(this->_update.open_BTC_ETH > this->_update.close_BTC_ETH)
        std::cout << "sell BTC_ETH 20" << std::endl;
    else
        std::cout << "pass" << std::endl;
}