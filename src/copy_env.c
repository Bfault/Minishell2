/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** copy_env.c
*/

#include "mysh.h"

char *give_name(char *str)
{
    char *result = NULL;
    int count = 0;

    for (int i = 0; str[i] != 61; i++)
        count = i + 1;
    result = my_malloc(sizeof(char) * count + 1);
    for (int i = 0; str[i] != 61; i++)
        result[i] = str[i];
    return (result);
}

int count_value(char *str)
{
    int active = 0;
    int i = 0;
    int count = 0;

    while (str[i]) {
        if (str[i - 1] == 61 || active) {
            active = 1;
            count++;
        }
        i++;
    }
    return (count);
}

char *give_value(char *str)
{
    char *result = NULL;
    int i = 0;
    int active = 0;

    result = my_malloc(sizeof(char) * count_value(str) + 1);
    for (int j = 0; str[i]; i++)
        if (str[i - 1] == 61 || active) {
            active = 1;
            result[j] = str[i];
            j++;
        }
    return (result);
}

void copy_env(cargo_t *cg, char **envp)
{
    char *name = NULL;
    char *value = NULL;

    cg->env_list = NULL;
    cg->envp = NULL;
    for (int i = 0; envp[i]; i++) {
        name = give_name(envp[i]);
        value = give_value(envp[i]);
        if (strc(name, "PWD")) {
            cg->env_list = env_append(&cg->env_list, my_strdup("OLD_PWD")
            , my_strdup(value), i);
            i++;
        }
        cg->env_list = env_append(&cg->env_list, name, value, i);
    }
}