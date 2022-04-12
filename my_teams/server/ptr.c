/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** ptr
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib.h"
#include "server.h"
#include "logging_client.h"
#include "logging_server.h"

char *format_string(char *name)
{
    int inc = 1;
    int ind = 0;
    char *copy = malloc(sizeof(char) * (strlen(name)));

    while (name[inc + 1] != '\0') {
        copy[ind] = name[inc];
        ind++;
        inc++;
    }
    copy[ind] = '\0';
    return (copy);
}

int users_fct(char **name, list_t **fds, server_t *serv)
{
    print_content(name[1], fds, serv);
}

int login_fct(char **name, list_t **fds, server_t *serv)
{
    if (name[1] != NULL) {
        char *copy = format_string(name[1]);
        list_t *node = get_client_fd(fds, serv->inc);
        char *save = NULL;

        if (node->status == false) {
            if (check_if_users_exist(copy) == true) {
                save = my_strcat("12 -", get_logged_id(copy, fds, serv), ' ');
                save = my_strcat(save, copy, ' ');
                save = strcat(save, "\r\n");
                user_logged_in_and_out(copy, fds, serv, 1);
                server_event_user_logged_in(get_logged_id(copy, fds, serv));
                write(serv->inc, save, strlen(save));
            } else
                save_users_in_txt(copy, fds, serv);
            node->name = strdup(copy);
            node->status = true;
        } else
            write(serv->inc, "31 - A user is already logged in\r\n", 34);
    } else
        write(serv->inc, "31 - Invalid username\r\n", 24);
}

int logout_fct(char **name, list_t **fds, server_t *serv)
{
    list_t *node = get_client_fd(fds, serv->inc);

    if (node->status == true) {
        user_logged_in_and_out(node->name, fds, serv, 0);
        node->status = false;
        server_event_user_logged_out(get_logged_id(node->name, fds, serv));
        write(serv->inc, "15 - User successfully logged out\n", 34);
    }
    close_client(serv, fds);
    return (0);
}

int commands(char **action, list_t **fds, server_t *serv)
{
    int idx = 0;
    int (*list[4])(char **, list_t **, server_t *) = {login_fct, logout_fct,
    users_fct, user_id_check};
    char *cmd_list[5] = {"/login", "/logout", "/users", "/user", NULL};

    while (cmd_list[idx]) {
        if (strcmp(action[0], cmd_list[idx]) == 0)
            list[idx](action, fds, serv);
        idx += 1;
    }
    return (0);
}