/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-quentin.garcia
** File description:
** cmd_mana
*/

#include "ftp.h"

ftp_t *create_my_struct()
{
    ftp_t *client = malloc(sizeof(ftp_t));
    if (client == NULL)
        return (NULL);
    client->pass = false;
    client->user = false;
    client->first = false;
    client->log = false;
    client->error = false;
    return client;
}

bool input_is_cmd(char *input, char **buf, ftp_t *client)
{
    int idx = 0;
    char *cmd[] = {"USER", "PASS", "CWD", "CDUP", "QUIT", "DELE", "PWD",
    "PASV", "PORT", "HELP","NOOP", "RETR", "STOR", "LIST", NULL};

    while(cmd[idx] != NULL) {
        if(strcmp("USER", input) == 0 && strcmp(" ", buf[1]) == 0 )
            return (true);
        if (strcmp(cmd[idx], input) == 0) {
            if(client->pass == false && client->user == false)
                return true;
            return (true);
            }
        idx += 1;
    }
    return (false);
}

bool command_manager(int client_fd)
{
    char *buffer;
    size_t size;
    FILE *file_stream_fd = fdopen(dup(client_fd), "r");
    ftp_t *client = create_my_struct();

    write(client_fd, "220 OK\r\n", 8);
    for (; getline(&buffer, &size, file_stream_fd) > 0;) {
        if (strcmp(buffer, "QUIT\r\n") == 0) {
            write(client_fd, "221 - Connection: Closed\r\n", 5);
            return false;
        }
        user(buffer, client_fd, client);
    }
    return true;
}