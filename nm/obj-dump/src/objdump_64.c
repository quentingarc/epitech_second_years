/*
** EPITECH PROJECT, 2021
** B-PSU-400-BDX-4-1-nmobjdump-quentin.garcia
** File description:
** objdump_64
*/

#include "objdump.h"
#include <stdio.h>

void elf_64(void *mapf, char **av, int ind)
{
    Elf64_Ehdr *header;

    header = mapf;
    printf("\n%s:%5cfile format ", av[ind], ' ');
    printf("elf64-x86-64");
    printf("\narchitecture: i386:x86-64, flags ");
    printfl_64(header);
    if (header->e_entry != 0)
        printf("\nstart address %018p\n\n", header->e_entry);
    else
        printf("\nstart address 0x0000000000000000\n\n");
    sections_64(mapf, header);
}

int sections_64(void *mapf, Elf64_Ehdr *elf)
{
    Elf64_Shdr *shdr = (Elf64_Shdr *)(mapf + elf->e_shoff);
    char *shtab = mapf + shdr[elf->e_shstrndx].sh_offset;
    int counter = 0;

    while (counter < elf->e_shnum)
    {
        printf("Contents of section %s:\n", shtab + shdr[counter].sh_name);
        counter++;
    }
    return (0);
}