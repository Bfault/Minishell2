/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** env_create.c
*/

#include "mysh.h"

env_t *env_create(char *name, char *value)
{
    env_t *cell = my_malloc(sizeof(env_t));

    if (!cell)
        return (0);
    cell->name = name;
    cell->value = value;
    cell->next = NULL;
    return (cell);
}