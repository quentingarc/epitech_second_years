/*
** EPITECH PROJECT, 2021
** B-PSU-400-BDX-4-1-nmobjdump-quentin.garcia
** File description:
** instaure
*/

#include "objdump.h"
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>

void rd_file(int fd, int file_size, char **av, int ind)
{
    char *mapf = mmap(0, file_size, PROT_READ, MAP_PRIVATE, fd, 0);

    if ((void *)mapf == MAP_FAILED)
    {
        printf("objdump: %s: file format not recognized", av[ind]);
        return;
    }
    if (file_size < 4 || strncmp(mapf, "\x7f\x45\x4c\x46", 4))
    {
        printf("objdump: %s: File format not recognized\n", av[ind]);
        munmap(mapf, file_size);
        return;
    }
    if ((unsigned char)mapf[4] == ELF64)
        elf_64((void *)mapf, av, ind);
    if ((unsigned char)mapf[4] == ELF32)
        elf_32((void *)mapf, av, ind);
    munmap(mapf, file_size);
}
