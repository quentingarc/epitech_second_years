/*
** EPITECH PROJECT, 2020
** B-PSU-400-BDX-4-1-malloc-quentin.garcia
** File description:
** malloc.h
*/

#ifndef _my_malloc_H
#define _my_malloc_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct malloc_s
{
    bool a;
    void *b;
    size_t inc;
    struct malloc_s *next;
} malloc_t;

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb , size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);
void *init_list(malloc_t **another_malloc, size_t nbr);
void *push_back(malloc_t **another_malloc, size_t nbr);
#endif /* _my_malloc_H*/
