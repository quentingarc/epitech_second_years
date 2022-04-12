/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** init_list
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

list_t *init_list(list_t **list, int fd)
{
    list_t *node = malloc(sizeof(list_t));
    list_t *tmp = *list;

    if (node == NULL)
        return (NULL);
    node ->status = false;
    if (*list == NULL) {
        node->data = fd;
        node->next = NULL;
        node->previous = NULL;
        *list = node;
    } else {
        while (tmp->next)
            tmp = tmp->next;
        node->data = fd;
        node->next = NULL;
        node->previous = tmp;
        tmp->next = node;
    }
    return (*list);
}

void init_list_user(is_logged_t **list, char *user)
{
    is_logged_t *node = malloc(sizeof(is_logged_t));
    is_logged_t *tmp = NULL;

    if (node == NULL)
        return;
    if (*list == NULL) {
        node->user = strdup(user);
        node->next = NULL;
        *list = node;
    } else {
        tmp = *list;
        while (tmp->next != NULL)
            tmp = tmp->next;
        node->user = strdup(user);
        node->next = NULL;
        tmp->next = node;
    }
}

list_t *remove_node(list_t **list, int fd)
{
    list_t *tmp = *list;

    if ((*list)->data == fd) {
        *list = (*list)->next;
        return (*list);
    }
    while (tmp->next) {
        if (tmp->data == fd) {
            tmp->next->previous = tmp->previous;
            tmp->previous->next = tmp->next;
        }
        tmp = tmp->next;
    }
    if (tmp->next == NULL && tmp->data == fd)
        tmp->previous->next = NULL;
    return (*list);
}

void print_list(list_t *list)
{
    for (; list != NULL; list = list->next) {
        my_put_nbr(list->status);
        write(1, "->", 2);
        write(1, " ", 1);
    }
    write(1, "NULL\n", 5);
}

int print_is_log(is_logged_t *is_log)
{
    int tmp = 0;
    for (; is_log != NULL; is_log = is_log->next) {
        tmp = my_printf(is_log->user);
        write(1, "\n", 2);
        write(1, "", 1);
    }
    return (tmp);
}