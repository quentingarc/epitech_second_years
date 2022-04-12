/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-teo.martos
** File description:
** init_struct
*/

#include <stdlib.h>
#include "server.h"
#include "lib.h"

void set_variables(server_t *serv, struct sockaddr_in server)
{
    serv->server = server;
    FD_ZERO(&serv->fdmax);
    FD_ZERO(&serv->fdread);
    FD_SET(serv->socket, &serv->fdmax);
    serv->max = serv->socket;
    serv->inc = 0;
}

server_t *init_serv(char *port)
{
    struct sockaddr_in server;
    server_t *serv = malloc(sizeof(server_t));

    if (serv == NULL)
        return (NULL);
    serv->socket = socket(AF_INET, SOCK_STREAM, 0);
    serv->user = 0;
    if (serv->socket == -1)
        return (NULL);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(atoi(port));
    if (bind(serv->socket, (struct sockaddr *)&server, sizeof(server)) < 0)
        return (NULL);
    if (listen(serv->socket, 1000) == -1)
        return (NULL);
    set_variables(serv, server);
    return (serv);
}