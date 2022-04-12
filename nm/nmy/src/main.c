/*
** EPITECH PROJECT, 2021
** B-PSU-400-BDX-4-1-nmobjdump-quentin.garcia
** File description:
** main
*/

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my_nm.h"

int main(int ac, char **av)
{
    int fd = 0;
    int ind = 1;
    struct stat st;

    if (ac < 2)
        return (0);
    while (ind < ac)
    {
        fd = open(av[ind], O_RDONLY);
        if (fd < 0 || fstat(fd, &st) != 0)
            printf("nm: '%s': No such file\n", av[ind]);
        else
        {
            rd_file(fd, st.st_size, av, ind);
            close(fd);
        }
        ind++;
    }
    return 0;
}
