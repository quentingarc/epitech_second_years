/*
** EPITECH PROJECT, 2021
** nasm
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
    char *tmp = strdup("toto");
    char *tmp_bis = strdup("test");
    //void *s = malloc(10);
    //void *z = malloc(10);
    //printf("%lu\n", strlen(tmp));
    //printf("%d\n", strcmp(tmp, tmp_bis));
    printf("%s\n", strchr(tmp, 'o'));
    //printf("%d\n", strncmp(tmp, tmp_bis, 2));
    //printf("%s\n", memset(s, 'e', 5));
    //printf("%s\n", memcpy(tmp, tmp_bis, 7));
    ///printf("%d\n", strcasecmp(tmp, tmp_bis));

    return (0);
}
