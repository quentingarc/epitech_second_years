/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** save_users
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib.h"
#include "server.h"
#include "logging_client.h"
#include "logging_server.h"

void save_users_in_txt(char *user, list_t **fds, server_t *serv)
{
    list_t *node = get_client_fd(fds, serv->inc);
    FILE *file = fopen("users.txt", "a+");
    char *random_uuid = get_id();
    char *concat = my_strcat("12 -", random_uuid, ' ');
    concat = my_strcat(concat, user, ' ');
    concat = strcat(concat, "\r\n");
    fprintf(file, "%s|%s|%d|\n", user, random_uuid, 1);
    server_event_user_created(random_uuid, user);
    server_event_user_logged_in(random_uuid);
    write(serv->inc, concat, strlen(concat));
    fclose(file);
}

bool check_if_users_exist(char *user)
{
    char *content = NULL;
    size_t size = 10;
    FILE *file = fopen("users.txt", "r");

    while (getline(&content, &size, file) != -1) {
        if (strncmp(
            strndup(content, strlen(content) -1), user, strlen(user)) == 0) {
            fclose(file);
            return (true);
        }
    }
    fclose(file);
    free(content);
    return (false);
}

void modif_status(server_t *serv, char *user, is_logged_t *logged, int status)
{
    is_logged_t *tmp = logged;
    char **users = NULL;
    char *save = NULL;
    FILE *file = fopen("users.txt", "r+");

    while (tmp) {
        users = my_str_to_word_array(tmp->user);
        if (strcmp(users[0], user) == 0) {
            fprintf(file, "%s|%s|%d|\n", users[0], users[1], status);
        } else
            fprintf(file, "%s\n", tmp->user);
        tmp = tmp->next;
    }
    fclose(file);
}

void user_logged_in_and_out(char *user, list_t **list,
server_t *serv, int status)
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
    modif_status(serv, user, logged, status);
}

void print_content(char *user, list_t **list,
server_t *serv)
{
    list_t *node = get_client_fd(list, serv->inc);

    if (node->status == false) {
        write(serv->inc, "31 - A user is not logged\r\n", 26);
        return;
    }
    write(serv->inc, "34 - Print list\r\n", 17);
}