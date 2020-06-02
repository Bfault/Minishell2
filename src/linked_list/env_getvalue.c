/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** env_getvalue.c
*/

#include "mysh.h"

char *env_getvalue(env_t **list, int pos)
{
    env_t *tmp = *list;

    if (!tmp)
        return (NULL);
    for (int i = 0; tmp && i < pos; i++)
        tmp = tmp->next;
    return ((tmp) ? tmp->value : NULL);
}