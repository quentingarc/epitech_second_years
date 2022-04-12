/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** get_user_id
*/

#include <uuid/uuid.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "server.h"

char *get_id(void)
{
    uuid_t uuid;
    char *random_uuid = malloc(sizeof(char) * (UUID_STR_LEN + 1));

    uuid_generate_random(uuid);
    uuid_unparse_lower(uuid, random_uuid);
    return (random_uuid);
}

char *get_logged_id(char *user, list_t **list, server_t *serv)
{
    FILE *file = fopen("users.txt", "r+");
    char *content = NULL;
    size_t size = 10;
    is_logged_t *logged = NULL;
    char **save = NULL;
    list_t *node = get_client_fd(list, serv->inc);

    while (getline(&content, &size, file) != -1) {
        content = strndup(content, strlen(content) - 1);
        init_list_user(&logged, content);
        if (node->status == false) {
            save = my_str_to_word_array(logged->user);
            return (save[1]);
        }
    }
    fclose(file);
    return (NULL);
}

char **check_logged_id(char *user)
{
    FILE *file = fopen("users.txt", "r");
    char *content = NULL;
    size_t size = 10;
    char **save = NULL;

    while (getline(&content, &size, file) != -1)
    {
        content = strndup(content, strlen(content) - 1);
        save = my_str_to_word_array(content);
        if (strcmp(user, save[1]) == 0)
        {
            fclose(file);
            return (save);
        }
    }
    fclose(file);
    return NULL;
}

int user_id_check(char **name, list_t **fds, server_t *serv)
{
    char *copy = format_string(name[1]);
    char **info = check_logged_id(copy);
    char *tmp = NULL;
    if (info == NULL)
    {
        write(serv->inc, "31 - A user is not logged\r\n", 27);
        return 0;
    }
    tmp = my_strcat("33 -", info[1], ' ');
    tmp = my_strcat(tmp, info[0], ' ');
    tmp = my_strcat(tmp, info[2], ' ');
    tmp = strcat(tmp, "\r\n");
    write(serv->inc, tmp, strlen(tmp));
    return 0;
}