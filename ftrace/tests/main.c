/*
** EPITECH PROJECT, 2021
** B-PSU-402-BDX-4-1-strace-quentin.garcia
** File description:
** main
*/

//MAIN TO USE MY STRACE----------------------------------------------
#include <unistd.h>

int main(void)
{
    write(1, 'A', 1);
    return (0);
}