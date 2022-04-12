/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-quentin.garcia
** File description:
** ftp
*/

#ifndef FTP_H
#define FTP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>
#include <sys/select.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>

typedef struct ftp_s 
{
    bool user;
    bool pass;
    bool first;
    bool log;
    bool error;
} ftp_t;


int launch_ftp(char *port);
bool command_manager(int client_fd);
char **my_str_to_word_array(char *str);
void user(char *buffer, int client_fd, ftp_t *client);
ftp_t *create_my_struct();
void cmd_log(ftp_t *client, int client_fd, char **buf);
bool input_is_cmd(char *input, char **buf, ftp_t *client);

void user(char *buffer, int client_fd, ftp_t *client);
void login(ftp_t *client, int client_fd, char **buf, char *buffer);

void noop(int client_fd, char **buf, ftp_t *client);
void help(int client_fd, char **buf, ftp_t *client);
void cwd(int client_fd, char **buf, ftp_t *client);
void cdup(int client_fd, char **buf, ftp_t *client);
void port(int client_fd, char **buf, ftp_t *client);
void pasv(int client_fd, char **buf, ftp_t *client);
void stor(int client_fd, char **buf, ftp_t *client);
void retr(int client_fd, char **buf, ftp_t *client);

#endif
