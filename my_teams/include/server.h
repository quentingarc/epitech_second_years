/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-teo.martos
** File description:
** serveur
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>
#include <sys/select.h>
#include <stdbool.h>
#include <signal.h>
#include "lib.h"

typedef struct server_s
{
    int socket;
    struct sockaddr_in server;
    int user;
    int max;
    int inc;
    int client;
    fd_set fdmax;
    fd_set fdread;
} server_t;

static volatile sig_atomic_t sig = 1;

                /* struct */

server_t *init_serv(char *port);

                /* server */

char *format_string(char *name);
int client_connection(server_t *server);
bool check_if_users_exist(char *user);
void print_content(char *user, list_t **list, server_t *serv);
void user_logged_in_and_out(char *user, list_t **list, server_t *serv,
int status);
int commands(char **action, list_t **fds, server_t *serv);
void save_users_in_txt(char *user, list_t **fds, server_t *serv);
void modif_status(server_t *serv, char *user, is_logged_t *logged, int status);
is_logged_t *get_file_content(char *user, list_t **list, server_t *serv);
char *get_logged_id(char *user, list_t **list, server_t *serv);
int user_id_check(char **name, list_t **fds, server_t *serv);
int send_signal(char *user, list_t **list, server_t *serv, int status);
void logout_server(void);
void logout_client(list_t **list, server_t *serv);
is_logged_t *get_logged_client(is_logged_t **list, char *user);
int close_client(server_t *server, list_t **list);

#endif /* !SERVER_H_ */