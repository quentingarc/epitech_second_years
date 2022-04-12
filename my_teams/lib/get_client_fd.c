/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** get_client_fd
*/

#include "lib.h"

list_t *get_client_fd(list_t **list, int fd)
{
    list_t *tmp = *list;

    for (; tmp && tmp->data != fd; tmp = tmp->next)
        continue;
    return (tmp);
}

is_logged_t *get_logged_client(is_logged_t **list, char *user)
{
    is_logged_t *tmp = *list;

    for (; tmp && tmp->user != user; tmp = tmp->next)
        continue;
    return (tmp);
}