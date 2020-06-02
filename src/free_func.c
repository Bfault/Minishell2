/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** free_func.c
*/

#include "mysh.h"

void free_all(cargo_t *cg, char *tmp)
{
    env_free(&cg->env_list);
    for (int i = 0; cg->envp[i]; i++)
        if (cg->envp[i])
            free(cg->envp[i]);
    free(cg->envp);
    free(cg->prompt);
    free(tmp);
}