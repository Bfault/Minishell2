/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** env_getpos.c
*/

#include "mysh.h"

int env_getpos(env_t **list, char *name)
{
    env_t *tmp = *list;
    int pos = 0;

    while (tmp && !strc(tmp->name, name)) {
        tmp = tmp->next;
        pos++;
    }
    return ((tmp) ? pos : -1);
}