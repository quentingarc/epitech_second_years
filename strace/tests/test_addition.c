/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** test_get_env_info
*/

#include <criterion/criterion.h>

int addition_function(int nb1, int nb2);

Test(test_2, simple_addition_test)
{
    int nb1 = 1;
    int nb2 = 2;

    cr_assert_eq(addition_function(nb1, nb2), 3);
}