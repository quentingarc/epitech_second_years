/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "Parser.hpp"

int	main(int ac, char **av)
{
    Parser checker;

    if (ac != 2 || checker.check_file_name(av[1]) == false)
        return (84);
    if (checker.check_chipsets(checker.get_file_content(av[1])) == false
    || checker.check_links(checker.get_file_content(av[1])) == false)
        return (84);
    checker.get_chipsets(av[1]);
    checker.get_links(av[1]);
    return (0);
}