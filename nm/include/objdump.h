/*
** EPITECH PROJECT, 2021
** B-PSU-400-BDX-4-1-nmobjdump-quentin.garcia
** File description:
** objdump
*/

#ifndef _objdump_
#define _objdump_

#include <elf.h>

#define ELF32		0x1
#define ELF64		0X2

#define BFD_NO_FLAGS    0x00
#define HAS_RELOC       0x01
#define EXEC_P          0x02
#define HAS_LINENO      0x04
#define HAS_DEBUG       0x08
#define HAS_SYMS        0x10
#define HAS_LOCALS      0x20
#define DYNAMIC         0x40
#define WP_TEXT         0x80
#define D_PAGED         0x100


void rd_file(int fd, int file_size, char **av, int ind);

void elf_64(void *mapf, char **av, int ind);

void printfl_64 (Elf64_Ehdr *elf);


void printfl_32(Elf32_Ehdr *elf);
void elf_32(void *mapf, char **av, int ind);
int sections_64(void *mapf, Elf64_Ehdr *elf);
int sections_32(void *mapf, Elf32_Ehdr *elf);

#endif

