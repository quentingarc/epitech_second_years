/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-quentin.garcia
** File description:
** cmdBis
*/
#include "ftp.h"

void noop(int client_fd, char **buf, ftp_t *client)
{
    if (strncmp(buf[0], "NOOP", strlen("NOOP")) == 0) {
        write(client_fd, "200 - NOOP ok\r\n", 15);
        client->error = true;
        }
}

void help(int client_fd, char **buf, ftp_t *client)
{
    if (strncmp(buf[0], "HELP", strlen("HELP")) == 0) {
        write(client_fd, "214 - HELP ok\r\n", 15);
        client->error = true;
        }
}
void cwd(int client_fd, char **buf, ftp_t *client)
{
    if (strncmp(buf[0], "CWD", strlen("CWD")) == 0) {
        write(client_fd, "250 - CWD ok\r\n", 14);
        client->error = true;
        }
}
void cdup(int client_fd, char **buf, ftp_t *client)
{
    if (strncmp(buf[0], "CDUP", strlen("CDUP")) == 0) {
        write(client_fd, "200 - CDUP ok\r\n", 15);
        client->error = true;
        }
}