/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** get_user_index
*/

int get_user_index(char *user)
{
    int inc = 0;

    while (user[inc]) {
        if (user[inc] == '|')
            return (inc);
        inc++;
    }
    return (0);
}