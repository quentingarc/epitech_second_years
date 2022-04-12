/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-teo.martos
** File description:
** path_command
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"
#include "server.h"

int accept_client(server_t *serv, list_t **list)
{
    socklen_t size = sizeof(struct sockaddr_in);
    int fd = accept(serv->socket, (struct sockaddr *)&serv->server, &size);

    if (fd == -1)
        perror("accept");
    else {
        FD_SET(fd, &serv->fdmax);
        if (fd > serv->max)
            serv->max = fd;
        init_list(list, fd);
    }
    return (0);
}

int close_client(server_t *server, list_t **list)
{
    shutdown(server->inc, SHUT_RDWR);
    close(server->inc);
    FD_CLR(server->inc, &server->fdmax);
    remove_node(list, server->inc);
    return (0);
}

int client_request(server_t *server, list_t **list)
{
    size_t size = 10;
    char *input = NULL;
    char **command = NULL;
    FILE *fd = fdopen(dup(server->inc), "r");

    if (getline(&input, &size, fd) == EOF) {
        logout_client(list, server);
        close_client(server, list);
        return (84);
    }
    input = strndup(input, strlen(input) - 1);
    command = my_str_to_word_array(input);
    commands(command, list, server);
    return (0);
}

void decoy(int decoy)
{
    sig = 0;
}

int client_connection(server_t *server)
{
    list_t *list = NULL;

    signal(SIGINT, decoy);
    while (sig != 0) {
        server->fdread = server->fdmax;
        if (select(server->max + 1, &server->fdread, NULL, NULL, NULL) == -1)
            break;
        server->inc = 0;
        while (server->inc <= server->max) {
            if (FD_ISSET(server->inc, &server->fdread)) {
                if (server->inc == server->socket)
                    accept_client(server, &list);
                else
                    client_request(server, &list);
            }
            server->inc += 1;
        }
    }
    logout_server();
    return (0);
}