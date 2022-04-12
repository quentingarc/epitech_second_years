/*
** EPITECH PROJECT, 2021
** B-PSU-400-BDX-4-1-nmobjdump-quentin.garcia
** File description:
** flag_32
*/

#include "objdump.h"
#include <stddef.h>
#include <stdio.h>

void printfl_32(Elf32_Ehdr *elf)
{
    uint32_t flags;

    if (elf->e_type == ET_REL)
    {
        flags = HAS_RELOC + HAS_SYMS;
        printf("0x%08x:\n", flags);
        printf("HAS_RELOC, HAS_SYMS");
    }
    if (elf->e_type == ET_EXEC)
    {
        flags = HAS_SYMS + EXEC_P + D_PAGED;
        printf("0x%08x:\n", flags);
        printf("EXEC_P, HAS_SYMS, D_PAGED");
    }
    if (elf->e_type == ET_DYN)
    {
        flags = HAS_SYMS + DYNAMIC + D_PAGED;
        printf("0x%08x:\n", flags);
        printf("HAS_SYMS, DYNAMIC, D_PAGED");
    }
}