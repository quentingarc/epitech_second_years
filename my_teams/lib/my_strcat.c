/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** my_strcat
*/

#include <string.h>
#include <stdlib.h>

char *my_strcat(char *dest, char *src, char c)
{
    int src_len = strlen(src);
    int dest_len = strlen(dest);
    char *save = malloc(sizeof(char) * (src_len + dest_len) + 1);

    dest_len = 0;
    src_len = 0;
    while (dest[dest_len] != '\0') {
        save[dest_len] = dest[dest_len];
        dest_len = dest_len + 1;
    }
    save[dest_len] = c;
    dest_len = dest_len + 1;
    while (src[src_len] != '\0') {
        save[dest_len + src_len] = src[src_len];
        src_len = src_len + 1;
    }
    save[dest_len + src_len] = '\0';
    return (save);
}