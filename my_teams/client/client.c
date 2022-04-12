/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** server
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "client.h"
#include "lib.h"
#include "logging_client.h"

int get_backslash(char *string)
{
    int inc = 0;

    while (string[inc]) {
        if (string[inc] == '\n')
            return (inc);
        inc++;
    }
    return (0);
}

int get_server_messages(client_t *client)
{
    size_t size = 10;
    char *input = malloc(sizeof(char) * (size + 1));
    FILE *fd = fdopen(dup(client->socket), "r");
    char **aray = NULL;
    client->is_logged = false;

    if (getline(&input, &size, fd) == EOF) {
        my_printf("Get fd error\n");
        return (84);
    }
    input = strndup(input, strlen(input) - 2);
    aray = my_str_to_word_array(input);
    if (strcmp(aray[0], "34") == 0) {
        print_all();
    } else if (strcmp(aray[0], "31") == 0)
        client_error_unauthorized();
    if (strcmp(aray[0], "12") == 0)
        login_events(aray, client);
    else if (strcmp(aray[0], "33") == 0)
        client_print_user(aray[3], aray[2], atoi(aray[4]));
    return (0);
}

int send_messages_to_server(client_t *client)
{
    size_t size = 10;
    char *input = malloc(sizeof(char) * (size + 1));
    char *stock = NULL;
    char *input_message = NULL;
    char **save = NULL;

    if (getline(&input, &size, stdin) == EOF) {
        my_printf("Get message error\n");
        return (84);
    }
    stock = malloc(sizeof(char) * (strlen(input) + 1));
    stock = strncpy(stock, input, get_backslash(input));
    input_message = strcat(stock, "\r\n");
    write(client->socket, input_message, strlen(input_message));
    save = my_str_to_word_array(input);
    if (strcmp(save[0], "/logout") == 0) {
        shutdown(client->socket, SHUT_RDWR);
        close(client->socket);
        if (client->is_logged == true)
            client_event_logged_out(client->uuid, client->user);
        return (84);
    }
    return (0);
}

void decoy(int decoy)
{
    sig = 0;
}

int server_connection(client_t *client)
{
    fd_set fdvar;

    signal(SIGINT, decoy);
    while (sig != 0) {
        FD_ZERO(&fdvar);
        FD_SET(client->socket, &fdvar);
        FD_SET(STDIN_FILENO, &fdvar);
        if (select(client->socket + 1, &fdvar, NULL, NULL, NULL) == -1)
            break;
        if (FD_ISSET(client->socket, &fdvar)) {
            if (get_server_messages(client) == 84)
                return (84);
        } else if (FD_ISSET(STDIN_FILENO, &fdvar)) {
            if (send_messages_to_server(client) == 84)
                return (84);
        }
    }
    shutdown(client->socket, SHUT_RDWR);
    close(client->socket);
    return (0);
}