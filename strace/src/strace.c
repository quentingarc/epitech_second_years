/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** strace
*/

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>
#include "strace.h"
#include <string.h>

void start_tracing(flags_t *flags)
{
    ptrace(PTRACE_TRACEME, 0, NULL, NULL);
    kill(getpid(), SIGSTOP);
    execvp(flags->argv[1], flags->argv + 1);
    perror("Execve");
}

int handle_signal(int status)
{
    if (WIFSIGNALED(status)) {
        printf("Recieved signal %s\n", strsignal(status));
        return (TRACEE_STOPPED);
    }
    if (WIFSTOPPED(status))
        if (WSTOPSIG(status) != SIGSTOP && WSTOPSIG(status) != SIGTRAP)
            return (TRACEE_STOPPED);
    if (WIFEXITED(status)) {
        printf("+++ exited with %d +++\n", WEXITSTATUS(status));
        return (TRACEE_STOPPED);
    }
    return (TRACEE_CONTINUE);
}

void tracer_loop(pid_t tracee, flags_t *flags)
{
    int status = 0;
    struct user_regs_struct regs;

    waitpid(tracee, &status, 0);
    ptrace(PTRACE_SETOPTIONS, tracee, 0, PTRACE_O_TRACESYSGOOD);
    while (1) {
        ptrace(PTRACE_SINGLESTEP, tracee, NULL, NULL);
        waitpid(tracee, &status, 0);
        if (handle_signal(status) == TRACEE_STOPPED)
            break;
        ptrace(PTRACE_GETREGS, tracee, NULL, &(regs));
        if ((int)regs.orig_rax >= 0 && (int)regs.orig_rax <= 328)
            print_info(&regs, flags);
    }
}

int strace(flags_t *flags)
{
    pid_t tracee = fork();

    if (tracee == 0)
        start_tracing(flags);
    else
        tracer_loop(tracee, flags);
    return (0);
}