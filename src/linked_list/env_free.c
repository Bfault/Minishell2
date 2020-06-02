/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** env_free.c
*/

#include "mysh.h"

void env_free(env_t **env_list)
{
    env_t *list = *env_list;
    env_t *tmp = NULL;

    while (list) {
        tmp = list->next;
        free_cell(list);
        list = tmp;
    }
}