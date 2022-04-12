/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-quentin.garcia
** File description:
** identification
*/

#include "ftp.h"

void pass(char *buffer, int client_fd, char **buf, ftp_t *client)
{
    if (strncmp(buf[0], "PASS", strlen("PASS")) == 0)
    {
        if (strncmp(buffer, "PASS \r\n", 7) == 0)
            client->pass = true;
    }
    login(client, client_fd, buf, buffer);
}

void user(char *buffer, int client_fd, ftp_t *client)
{
    char **buf = my_str_to_word_array(buffer);
    if (strncmp(buf[0], "USER", strlen("USER")) == 0 && buf[1] != NULL) {
        if (strncmp(buf[1], "Anonymous", strlen("Anonymous") - 1) != 0) {
            write(client_fd, "331 - Please specify the password\r\n", 35);
            client->user = false;
            client->first = true;
            return;
        } else {
            write(client_fd, "331 - Please specify the password\r\n", 35);
            client->user = true;
            client->first = true;
            return;
        }
    } else if (client->first == false &&
    strncmp(buf[0], "PASS", strlen("PASS")) == 0) {
        write(client_fd, "503 - Login with USER first\r\n", 29);
        return;
    }
    pass(buffer, client_fd, buf, client);
}