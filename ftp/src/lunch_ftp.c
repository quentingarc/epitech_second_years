/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-quentin.garcia
** File description:
** lunch_ftp
*/

#include "ftp.h"

int ftp(int socket_desc, int c, int client_fd, int pid)
{
    listen(socket_desc, 1000);
    struct sockaddr_in s_in_client;
    c = sizeof(struct sockaddr_in);
    puts("Waiting for incoming connections...");

    while (1) {
        
        client_fd = accept(socket_desc, 
        (struct sockaddr *)&s_in_client, (socklen_t*)&c);
        pid = fork();
        if (pid == 0){
            if(command_manager(client_fd) == false)
                shutdown(client_fd, SHUT_RDWR);
        }
    }
}

int launch_ftp(char *port)
{
    int socket_desc, new_socket, c, *new_sock;
    struct sockaddr_in server;
    int pid;
    int client_fd;

    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
        printf("Could not create socket");
    
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(atoi(port));

    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("bind");
        return (84);
    } ftp(socket_desc, c, client_fd, pid);
    return 0;
}