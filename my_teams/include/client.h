/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>
#include <sys/select.h>
#include <signal.h>
#include <stdbool.h>

typedef struct client_s
{
    int socket;
    struct sockaddr_in server;
    int connect;
    char *user;
    char *uuid;
    bool is_logged;
} client_t;

static volatile sig_atomic_t sig = 1;

client_t *init_client(char *port);
int server_connection(client_t *client);
void print_all(void);
void login_events(char **aray, client_t *client);

#endif /* !CLIENT_H_ */
