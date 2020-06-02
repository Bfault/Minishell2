/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** env_append.c
*/

#include "mysh.h"

env_t *env_append(env_t **list, char *name, char *value, int pos)
{
    env_t *tmp = *list;
    env_t *pre = tmp;
    env_t *cur = tmp;
    env_t *cell = env_create(name, value);

    if (pos == 0) {
        cell->next = tmp;
        return (cell);
    }
    for (int i = 0; i < pos; i++) {
        pre = cur;
        cur = cur->next;
    }
    pre->next = cell;
    cell->next = cur;
    return (tmp);
}