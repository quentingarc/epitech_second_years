/*
** EPITECH PROJECT, 2021
** B-PSU-400-BDX-4-1-nmobjdump-quentin.garcia
** File description:
** objdump_32
*/

#include "objdump.h"
#include <stdio.h>

void elf_32(void *mapf, char **av, int ind)
{
    Elf32_Ehdr *header;

    header = mapf;

    printf("\n%s:%5cfile format ", av[ind], ' ');
    printf("elf32-i386");
    printf("\narchitecture: i386, flags ");
    printfl_32(header);
    if (header->e_entry != 0)
        printf("\nstart address %010p\n\n", header->e_entry);
    else
        printf("\nstart address 0x00000000\n\n");
    sections_32(mapf, header);
}

int sections_32(void *mapf, Elf32_Ehdr *elf)
{
    Elf32_Shdr *shdr = (Elf32_Shdr *)(mapf + elf->e_shoff);
    char *shtab = mapf + shdr[elf->e_shstrndx].sh_offset;
    int counter = 0;

    while (counter < elf->e_shnum)
    {
        printf("Contents of section %s:\n", shtab + shdr[counter].sh_name);
        counter++;
    }
    return (0);
}