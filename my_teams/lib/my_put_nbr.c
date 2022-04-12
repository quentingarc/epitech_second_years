/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** my_put_nbr
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + '0');
    } else
        my_putchar((nb % 10) + '0');
    return (0);
}