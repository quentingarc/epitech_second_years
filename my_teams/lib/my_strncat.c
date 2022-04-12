/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** my_strncat
*/

#include <string.h>

char *my_strncat(char *dest, char const *src, int nb)
{
    int inc = 0;
    int dest_len = strlen(dest);

    while (inc < nb && src[inc] != '\0') {
        dest[dest_len + inc] = src[inc];
        inc = inc + 1;
    }
    dest[dest_len + nb] = '\0';
    return (dest);
}