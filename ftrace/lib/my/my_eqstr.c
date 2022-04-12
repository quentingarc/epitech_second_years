/*
** EPITECH PROJECT, 2021
** B-PSU-402-BDX-4-1-strace-quentin.garcia
** File description:
** my_eqstr
*/

int my_strcmp(char *str1, char *str2);

int my_eqstr(char *str1, char *str2)
{
    if (my_strcmp(str1, str2) == 1 && my_strcmp(str2, str1) == 1)
        return (1);
    else
        return (2);
}