/*
** EPITECH PROJECT, 2021
** B-PSU-400-BDX-4-1-nmobjdump-quentin.garcia
** File description:
** nm
*/

#ifndef _nmy_
#define _nmy_

#include <elf.h>

#define ELF32		0x1
#define ELF64		0X2


void rd_file(int fd, int file_size, char **av, int ind);
void nm_32();
void nm_64();

#endif

