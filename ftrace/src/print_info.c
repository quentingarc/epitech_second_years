/*
** EPITECH PROJECT, 2021
** B-PSU-402-BDX-4-1-strace-quentin.garcia
** File description:
** print_info
*/

#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include "strace.h"
#include "syscall_info.h"
#include <unistd.h>
#include <stdio.h>

void print_info(struct user_regs_struct *regs, flags_t *flags)
{
    size_t needed_reg[6];

    needed_reg[0] = regs->rdi;
    needed_reg[1] = regs->rsi;
    needed_reg[2] = regs->rdx;
    needed_reg[3] = regs->rcx;
    needed_reg[4] = regs->r8;
    needed_reg[5] = regs->r9;
    printf("Syscall %s(", sys_arr[regs->orig_rax].name);
    if (regs->orig_rax == 59) {
	    printf("\"%s\", [\"%s\"] , [/* %d vars */]\n", flags->argv[1],
        flags->argv[1], flags->env_size);
        return;
    }
    for (int i = 0; i < sys_arr[regs->orig_rax].arg_nbr; i++) {
        printf("0x%lx", needed_reg[i]);
        if (i < sys_arr[regs->orig_rax].arg_nbr - 1)
            printf(", ");
    }
    printf(") = %llx\n", regs->rax);
}