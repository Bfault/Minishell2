/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** env_modify.c
*/

#include "mysh.h"

void env_modify(env_t **list, char *value, int pos)
{
    env_t *tmp = *list;

    if (!tmp)
        return;
    for (int i = 0; tmp && i < pos; i++)
        tmp = tmp->next;
    free(tmp->value);
    tmp->value = my_strdup(value);
}