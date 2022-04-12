/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-quentin.garcia
** File description:
** cmd
*/

#include "ftp.h"

void list(int client_fd, char **buf, ftp_t *client)
{
    if (strncmp(buf[0], "LIST", strlen("LIST")) == 0) {
        write(client_fd, "150 - LIST ok\r\n", 15);
        client->error = true;
        }
}
void dele(int client_fd, char **buf, ftp_t *client)
{
    if (strncmp(buf[0], "DELE", strlen("DELE")) == 0) {
        write(client_fd, "250 - DELE ok\r\n", 15);
        client->error = true;
        }
}
void pwd(int client_fd, char **buf, ftp_t *client)
{
    if (strncmp(buf[0], "PWD", strlen("PWD")) == 0) {
        write(client_fd, "257 - PWD ok\r\n", 14);
        client->error = true;
        }
}

void cmd_log(ftp_t *client, int client_fd, char **buf)
{
    if (client->log == true) {
        noop(client_fd, buf, client);
        help(client_fd, buf, client);
        cwd(client_fd, buf, client);
        pwd(client_fd, buf, client);
        dele(client_fd, buf, client);
        list(client_fd, buf, client);
        retr(client_fd, buf, client);
        stor(client_fd, buf, client);
        pasv(client_fd, buf, client);
        port(client_fd, buf, client);
        cdup(client_fd, buf, client);
        if (client->error == false) {
            write(client_fd, "500 - Unknown command\r\n", 23);
            return;
        }
        client->error = false;
    }
}