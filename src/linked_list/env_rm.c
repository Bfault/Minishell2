/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** env_rm.c
*/

#include "mysh.h"

void free_cell(env_t *list)
{
    free(list->value);
    free(list->name);
    free(list);
}

env_t *env_rm(env_t **list, int pos)
{
    env_t *pre = *list;
    env_t *cur = *list;

    if (!(*list))
        return (NULL);
    if (pos == 0) {
        *list = (*list)->next;
        free_cell(cur);
        return (*list);
    }
    for (int i = 0; i < pos; i++) {
        pre = cur;
        cur = cur->next;
    }
    pre->next = cur->next;
    free_cell(cur);
    return (*list);
}