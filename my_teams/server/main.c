/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** main
*/

#include <string.h>
#include <stdlib.h>
#include "server.h"
#include "lib.h"

int main(int ac, char **av)
{
    if (ac != 2 || strlen(av[1]) < 4)
        return 84;
    server_t *serv = init_serv(av[1]);
    client_connection(serv);
    return (0);
}