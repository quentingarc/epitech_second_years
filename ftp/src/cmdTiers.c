/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-quentin.garcia
** File description:
** cmdTiers
*/

#include "ftp.h"

void port(int client_fd, char **buf, ftp_t *client)
{
    if (strncmp(buf[0], "PORT", strlen("PORT")) == 0) {
        write(client_fd, "200 - PORT ok\r\n", 15);
        client->error = true;
        }
}
void pasv(int client_fd, char **buf, ftp_t *client)
{
    if (strncmp(buf[0], "PASV", strlen("PASV")) == 0) {
        write(client_fd, "227 - PASV ok\r\n", 15);
        client->error = true;
        }
}
void stor(int client_fd, char **buf, ftp_t *client)
{
    if (strncmp(buf[0], "STOR", strlen("STOR")) == 0) {
        write(client_fd, "150 - STOR ok\r\n", 15);
        client->error = true;
        }
}
void retr(int client_fd, char **buf, ftp_t *client)
{
    if (strncmp(buf[0], "RETR", strlen("RETR")) == 0) {
        write(client_fd, "150 - RETR ok\r\n", 15);
        client->error = true;
        }
}