/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** print_users
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"
#include "client.h"
#include "logging_client.h"

void print_all(void)
{
    FILE *file = fopen("users.txt", "r+");
    char *content = NULL;
    size_t size = 10;
    char *tmp = NULL;
    char **array = NULL;

    while (getline(&content, &size, file) != -1) {
        content = strndup(content, strlen(content) - 1);
        array = my_str_to_word_array(content);
        client_print_users(array[1], array[0], atoi(array[2]));
    }
    fclose(file);
}