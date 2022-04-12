/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** logout_everyone
*/

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include "lib.h"
#include "server.h"

void set_server_statuts_to_zero(is_logged_t *logged)
{
    is_logged_t *tmp = logged;
    char **users = NULL;
    char *save = NULL;
    FILE *file = fopen("users.txt", "r+");

    while (tmp) {
        users = my_str_to_word_array(tmp->user);
        fprintf(file, "%s|%s|%d|\n", users[0], users[1], 0);
        tmp = tmp->next;
    }
    fclose(file);
}

void logout_server(void)
{
    FILE *file = fopen("users.txt", "r+");
    char *content = NULL;
    size_t size = 10;
    is_logged_t *logged = NULL;

    while (getline(&content, &size, file) != -1) {
        content = strndup(content, strlen(content) - 1);
        init_list_user(&logged, content);
    }
    fclose(file);
    set_server_statuts_to_zero(logged);
}