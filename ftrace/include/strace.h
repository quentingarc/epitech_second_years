/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** strace
*/

#ifndef STRACE_H_
#define STRACE_H_

#include "my.h"

typedef struct s_flags
{
    char s;
    char p;
    char no_flag;
    char **argv;
    char **env;
    int env_size;
    int argc;
} flags_t;

enum tracee_status {
    TRACEE_STOPPED = 0,
    TRACEE_CONTINUE = 1
};

union call_type {
    long word;
    char byte[8];
};

int strace(flags_t *flags);
void start_tracing(flags_t *flags);
void tracer_loop(pid_t tracee, flags_t *flags);
void print_info(struct user_regs_struct *regs, flags_t *flags);

#endif /* !STRACE_H_ */