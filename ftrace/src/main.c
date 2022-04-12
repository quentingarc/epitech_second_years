/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** bootstrap_try
*/

#include <stdio.h>
#include <unistd.h>
#include "strace.h"

static int no_argument(int a)
{
    fprintf(stderr, "strace: must have PROG [ARGS] or -p PID\n");
    fprintf(stderr, "Try 'strace -h' for more information.\n");
    return (a);
}

static flags_t check_flags(int as, char **av)
{
    flags_t flags;

    flags.s = 0;
    flags.p = 0;
    flags.no_flag = 1;
    flags.argc = as;
    for (int i = 0; i < as; i++)
    {
        if (my_strcmp(av[i], "-p") && my_strcmp("-p", av[i]))
            flags.p = 1;
        else if (my_strcmp(av[i], "-s") && my_strcmp("-s", av[i]))
            flags.s = 1;
    }
    if (flags.s == 1 || flags.p == 1)
        flags.no_flag = 0;
    flags.argv = av;
    return (flags);
}

int main(int args, char **argv, char **env)
{
    flags_t flags;
    int i = 0;

    if (args < 2)
        return (no_argument(84));
    if (my_eqstr(argv[1], "--help") == 1 || my_eqstr(argv[1], "-h") == 1)
    {
        printf("USAGE: ./strace [-s] [-p <pid>|<command>]\n");
        return (0);
    }
    flags = check_flags(args, argv);
    flags.env = env;
    for (i = 0; flags.env[i] != NULL; i++)
        ;
    flags.env_size = i;
    strace(&flags);
    return 0;
}