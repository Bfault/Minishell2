/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** env_ls.c
*/

#include "mysh.h"

int env_len(env_t **list)
{
    env_t *tmp = *list;
    int nb = 0;

    while (tmp) {
        tmp = tmp->next;
        nb++;
    }
    return (nb);
}