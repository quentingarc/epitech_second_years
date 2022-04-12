/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** login_envents
*/

#include <string.h>
#include "logging_client.h"
#include "client.h"

void login_events(char **aray, client_t *client)
{
    client_event_logged_in(aray[2], aray[3]);
    client->uuid = strdup(aray[2]);
    client->user = strdup(aray[3]);
    client->is_logged = true;
}