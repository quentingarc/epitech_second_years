/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-quentin.garcia
** File description:
** login
*/

#include "ftp.h"

void errorBis(ftp_t *client, int client_fd)
{
    if (client->pass == false && client->user == false && client->log == false)
    {
        write(client_fd, "530 - Please login with USER and PASS\r\n", 39);
        return;
    }
    else
    {
        write(client_fd, "500 - Unknown command\r\n", 23);
        return;
    }
}

void error(ftp_t *client, int client_fd, char **buf, char *buffer)
{
    if (input_is_cmd(buffer, buf, client) == false)
    {
        if (strncmp(buf[0], "USER", strlen("USER")) == 0
        && client->log == false)
        {
            write(client_fd, "500 - error : USER [name]\r\n", 27);
            return;
        }
        if (strncmp(buf[0], "PASS", strlen("PASS")) == 0 &&
        client->log == false)
        {
            write(client_fd, "500 - error : PASS [password]\r\n", 31);
            return;
        }
        errorBis(client, client_fd);
    }
}

void login_bis(ftp_t *client, int client_fd, char **buf, char *buffer)
{
    if (client->pass == true && client->user == true)
    {
        if (client->log == false)
        {
            write(client_fd, "230 - Login successful\r\n", 24);
            client->error = true;
        }
        client->log = true;
        cmd_log(client, client_fd, buf);
        return;
    }
    else if (client->pass == false && client->user == false &&
    buf[1] != NULL && client->log == false)
    {
        write(client_fd, "530 - Login incorrect\r\n", 23);
        client->first = false;
        return;
    }
    error(client, client_fd, buf, buffer);
}

void login(ftp_t *client, int client_fd, char **buf, char *buffer)
{
    if (client->pass == true && client->user == false && client->log == false)
    {
        write(client_fd, "331 - USER incorrect\r\n", 22);
        client->pass = false;
        client->first = false;
        return;
    }
    else if (client->pass == false && client->user == true
    && client->log == false)
    {
        write(client_fd, "530 - PASS incorrect\r\n", 22);
        return;
    }
    login_bis(client, client_fd, buf, buffer);
}