/*
** EPITECH PROJECT, 2021
** B-PSU-400-BDX-4-1-nmobjdump-quentin.garcia
** File description:
** establishes
*/

#include "my_nm.h"
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>

void rd_file(int fd, int file_size, char **av, int ind)
{
    char *nmapf = mmap(0, file_size, PROT_READ, MAP_PRIVATE, fd, 0);

    if ((void *)nmapf == MAP_FAILED)
    {
        printf("nm: Warning: '%s' is not an ordinary file\n", av[ind]);
        return;
    }
    if (file_size < 4 || strncmp((char *)nmapf, "\x7f\x45\x4c\x46", 4))
    {
        printf("nm: %s: File format not recognized\n", av[ind]);
        munmap(nmapf, file_size);
        return;
    }
    if ((unsigned char)nmapf[4] == ELF64)
        nm_64();
    if ((unsigned char)nmapf[4] == ELF32)
        nm_32();
    munmap(nmapf, file_size);
}

void nm_64()
{
    return;
}

void nm_32()
{
    return;
}