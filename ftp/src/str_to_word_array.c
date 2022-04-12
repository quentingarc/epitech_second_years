/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-quentin.garcia
** File description:
** str-to-word-array
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char **fill_array(char *str, char **array)
{
    int inc = 0;
    int array_y = 0;
    int array_x = 0;

    while (str[inc] != '\0') {
        if (str[inc] == ' ') {
            array_x = array_x + 1;
            array_y = 0;
            inc = inc + 1;
        }
        array[array_x][array_y] = str[inc];
        array_y = array_y + 1;
        inc = inc + 1;
    }
    array[array_x + 1] = NULL;
    return (array);
}

char **my_str_to_word_array(char *str)
{
    int len = strlen(str);
    char **array = malloc(sizeof(char *) * (len + 1));
    int inc = 0;

    while (inc < len) {
        array[inc] = malloc(sizeof(char *) * (len + 1));
        inc = inc + 1;
    }
    array = fill_array(str, array);
    return (array);
}