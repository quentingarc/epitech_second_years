/*
** EPITECH PROJECT, 2021
** B-CNA-410-BDX-4-1-trade-sergiu.hincu
** File description:
** trade
*/

#ifndef TRADE_HPP
#define TRADE_HPP

#include <string>
#include <iostream>
#include <vector>

typedef struct settings_s
{
    std::string player_names;
    std::string your_bot;
    int timebank;
    int time_per_move;
    int candle_interval;
    std::string candle_format;
    int candles_total;
    int candles_given;
    int initial_stack;
    float transaction_fee_percent;

} settings_t;

typedef struct update_s
{
    std::vector<std::string> pair_BTC_ETH;
    std::vector<float> date_BTC_ETH;
    std::vector<float> high_BTC_ETH;
    std::vector<float> low_BTC_ETH;
    std::vector<float> open_BTC_ETH;
    std::vector<float> close_BTC_ETH;
    std::vector<float> volume_BTC_ETH;

    std::vector<std::string> pair_USDT_ETH;
    std::vector<float> date_USDT_ETH;
    std::vector<float> high_USDT_ETH;
    std::vector<float> low_USDT_ETH;
    std::vector<float> open_USDT_ETH;
    std::vector<float> close_USDT_ETH;
    std::vector<float> volume_USDT_ETH;

    std::vector<std::string> pair_USDT_BTC;
    std::vector<float> date_USDT_BTC;
    std::vector<float> high_USDT_BTC;
    std::vector<float> low_USDT_BTC;
    std::vector<float> open_USDT_BTC;
    std::vector<float> close_USDT_BTC;
    std::vector<float> volume_USDT_BTC;

} update_t;

typedef struct stacks_s {
    std::vector<float> BTC;
    std::vector<float> ETH;
    std::vector<float> USDT;
} stacks_t;

class Trade
{
public:
    Trade(void);
    ~Trade(void);
    void mannagment(void);
    int executive(std::vector<std::string> separate);
    int executive_settings(std::vector<std::string> separate);
    int executive_update(std::vector<std::string> separate);
    void update(std::vector<std::string> separate);
    void settings(std::vector<std::string> separate);
    char *separate_line(std::string line);
    void parse_data(std::vector<std::string> separate);
    void parse_stacks(std::vector<std::string> separate);
    void mannagment_trade(std::vector<std::string> separate);
    void pass();

private:
    settings_t _settings;
    update_t _update;
    stacks_t _stacks;
};

std::vector<std::string> string_to_vector(std::string s, char c);

#endif