/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** my_str_to_word_array
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int my_char_is_alpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
    (c >= '0' && c <= '9'))
        return (1);
    else if (c == '/' || c == '"' || c == '-')
        return (1);
    return (0);
}

int calc_arr_size(char *str)
{
    int inc = 0;
    int nbr = 1;

    while (str[inc] != '\0')
    {
        if (my_char_is_alpha(str[inc]) == 1)
            nbr = nbr + 1;
        inc = inc + 1;
    }
    return (nbr);
}

int calc_str_len(char *str, int inc)
{
    while (my_char_is_alpha(str[inc]) == 1)
        inc = inc + 1;
    return (inc);
}

char *copy_str_to_array(char *str, int inc)
{
    int cx = 0;
    char *board = malloc(sizeof(char) * (calc_str_len(str, inc) + 1));

    while (my_char_is_alpha(str[inc]) == 1 && str[inc])
    {
        board[cx] = str[inc];
        cx = cx + 1;
        inc = inc + 1;
    }
    board[cx] = '\0';
    return (board);
}

char **my_str_to_word_array(char *str)
{
    char **board = malloc(sizeof(char *) * (calc_arr_size(str) + 1));
    int cy = 0;
    int inc = 0;

    while (str[inc] != '\0' && str[inc])
    {
        if (my_char_is_alpha(str[inc]) == 1 && str[inc] != '\0')
        {
            board[cy] = copy_str_to_array(str, inc);
            while (my_char_is_alpha(str[inc]) == 1 && str[inc])
                inc = inc + 1;
            cy = cy + 1;
        }
        inc = inc + 1;
    }
    board[cy] = NULL;
    return (board);
}