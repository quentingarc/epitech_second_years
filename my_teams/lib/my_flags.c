/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** my_flags
*/

#include <stdarg.h>

void my_putchar(char c);

void my_putstr(char const *str);

int my_put_nbr(int nb);

int d_flag(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
    return (0);
}

int i_flag(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
    return (0);
}

int c_flag(va_list ap)
{
    my_putchar(va_arg(ap, int));
    return (0);
}

int s_flag(va_list ap)
{
    my_putstr(va_arg(ap, char *));
    return (0);
}