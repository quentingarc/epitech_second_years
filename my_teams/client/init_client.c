/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** init_client
*/

#include <stdlib.h>
#include "client.h"

client_t *init_client(char *port)
{
    struct sockaddr_in cli;
    client_t *client = malloc(sizeof(client_t));

    if (client == NULL)
        return (NULL);
    client->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client->socket == -1)
        return (NULL);
    inet_aton(port, &cli.sin_addr);
    inet_ntoa(cli.sin_addr);
    cli.sin_family = AF_INET;
    cli.sin_addr.s_addr = INADDR_ANY;
    cli.sin_port = htons(atoi(port));
    client->connect = connect(client->socket, (struct sockaddr *)&cli,
    sizeof(cli));
    if (client->connect == -1)
        return (NULL);
    client->server = cli;
    return (client);
}