/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myftp-quentin.garcia
** File description:
** main
*/

#include "ftp.h"

int main(int argc, char ** argv)
{
    if (argc >= 2 && strcmp(argv[1], "-help") == 0){
        printf("USAGE: ./myftp port path\n      port is the port number ");
        printf("which the server socket listens\n      path is the path to ");
        printf("the home directory for the Anonymous user\n");
        return (0);
    } else
        return (launch_ftp(argv[1]));
    return 0;
}