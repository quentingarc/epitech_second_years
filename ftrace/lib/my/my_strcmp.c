/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** my_strcmp
*/

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    if (!str1 || (!str1 && !str2))
        return (0);
    for (int i = 0; str1[i] != '\0'; i++)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}