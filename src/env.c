/*
** EPITECH PROJECT, 2019
** PSU_minishell_2019
** File description:
** env.c
*/

#include "mysh.h"

void print_env(env_t **list, int *led)
{
    env_t *tmp_list = *list;

    while (tmp_list) {
        *led = display_msg(1, tmp_list->name);
        *led = display_msg(1, "=");
        *led = display_msg(1, tmp_list->value);
        *led = display_msg(1, "\n");
        tmp_list = tmp_list->next;
    }
}

void parse_it(env_t **list, char ***envp)
{
    env_t *tmp_list = *list;
    char **tmp_envp = *envp;

    for (int i = 0; tmp_list; i++, tmp_list = tmp_list->next)
        tmp_envp[i] = fusion_word(tmp_list->name, "=", tmp_list->value, NULL);
}

void update_env(cargo_t *cg)
{
    for (int i = 0; cg->envp && cg->envp[i]; i++)
        free(cg->envp[i]);
    if (cg->envp) free (cg->envp);
    cg->envp = my_malloc(sizeof(char *) * (env_len(&cg->env_list) + 1));
    cg->envp[env_len(&cg->env_list)] = NULL;
    parse_it(&cg->env_list, &cg->envp);
}