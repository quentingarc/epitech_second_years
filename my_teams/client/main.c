/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "client.h"
#include "lib.h"

int main(int ac, char **av)
{
    client_t *client = init_client(av[2]);
    if (client == NULL)
        perror("failed");
    server_connection(client);
    return (0);
}