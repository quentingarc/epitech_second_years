/*
** EPITECH PROJECT, 2020
** B-PSU-400-BDX-4-1-malloc-quentin.garcia
** File description:
** malloc.c
*/

#include "my_malloc.h"

malloc_t *my_malloc;

void *malloc(size_t size)
{
    malloc_t *tmp = NULL;
    if (my_malloc == NULL)
    {
        tmp = init_list(&my_malloc, size);
        if (tmp == NULL)
            return NULL;
        return tmp->b;
    }
    tmp = push_back(&my_malloc, size);
    if (tmp == NULL)
        return NULL;
    return tmp->b;
}

void *init_list(malloc_t **another_malloc, size_t nbr)
{
    if (*another_malloc == NULL)
    {
        malloc_t *init_mal = sbrk(sizeof(malloc_t));
        if (init_mal == (void *)-1)
            return NULL;
        init_mal->inc = nbr;
        init_mal->b = sbrk(nbr);
        if (init_mal->b == (void *)-1)
            return NULL;
        init_mal->next = NULL;
        init_mal->a = false;
        *another_malloc = init_mal;
        return init_mal;
    }
    return NULL;
}

void *push_back(malloc_t **another_malloc, size_t nbr)
{
    malloc_t *tmp = another_malloc;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    malloc_t *tbp = sbrk(sizeof(malloc_t));
    if (tbp == (void *)-1)
        return NULL;
    tbp->next->next = tbp;
    tbp->next->a  = false;
    tbp->next->inc = nbr;
    tbp->next->b = sbrk(nbr);
    if (tbp->next->b == (void *)-1)
        return NULL;
}