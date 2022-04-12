/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** my_printf
*/

#include <stdarg.h>

void my_putchar(char c);

int d_flag(va_list ap);

int i_flag(va_list ap);

int c_flag(va_list ap);

int s_flag(va_list ap);

int (*list[])(va_list ap) =
{
    &d_flag,
    &i_flag,
    &c_flag,
    &s_flag,
};

void check(char const *str, int inc, va_list *ap)
{
    char func[] = "dics";
    int i = 0;

    while (func[i] != '\0') {
        if (func[i] == str[inc]) {
            list[i](*ap);
            return;
        }
        i = i + 1;
    }
}

int my_printf(char const *str, ...)
{
    int inc = 0;
    va_list ap;

    va_start(ap, str);
    while (str[inc] != '\0') {
        if (str[inc] == '%') {
            inc = inc + 1;
            check(str, inc, &ap);
        } else
            my_putchar(str[inc]);
        inc = inc + 1;
    }
    va_end(ap);
    return (0);
}