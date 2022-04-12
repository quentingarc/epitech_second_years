/*
** EPITECH PROJECT, 2021
** B-NWP-400-BDX-4-1-myteams-teo.martos
** File description:
** lib
*/

#ifndef LIB_H_
#define LIB_H_

#include <stdbool.h>

typedef struct list
{
    int data;
    bool status;
    char *name;
    char *id;
    struct list *next;
    struct list *previous;
}list_t;

typedef struct is_logged
{
    char *user;
    struct is_logged *next;
} is_logged_t;

list_t *init_list(list_t **list, int fd);
list_t *remove_node(list_t **list, int fd);
void print_list(list_t *list);
int print_is_log(is_logged_t *is_log);
int list_user(is_logged_t *is_log);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_printf(char const *str, ...);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char *str);
char *my_strcat(char *dest, char *src, char c);
void user_re_logged_in(char *user);
void init_list_user(is_logged_t **list, char *user);
int get_user_index(char *user);
char *get_id(void);
list_t *get_client_fd(list_t **list, int fd);

#endif /* !LIB_H_ */
