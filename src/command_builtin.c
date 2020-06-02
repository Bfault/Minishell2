/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** command.c
*/

#include "mysh.h"

int test_setenv(int len, char *tmp, cargo_t *cg)
{
    if (len > 3) {
        cg->led = display_msg(2, "setenv: Too many arguments.\n");
        return (1);
    }
    if (alphanumeric(tmp, '_', 0)) {
        cg->led = display_msg(2,
        "setenv: Variable name must contain alphanumeric characters.\n");
        return (1);
    }
    return (0);
}

void command_setenv(cargo_t *cg, char **str)
{
    int len = 0;
    int pos = 0;
    char *value = my_strdup((str[2]) ? str[2] : "");
    char *name = my_strdup(str[1]);

    for (int i = 0; str[i]; i++)
        len++;
    if (test_setenv(len, str[1], cg)) {
        free(value);
        free(name);
        return;
    } else if ((pos = env_getpos(&cg->env_list, name)) != -1) {
        env_modify(&cg->env_list, value, pos);
        free(name);
    } else {
        cg->env_list = env_append((&cg->env_list), name,
        value, env_len(&cg->env_list));
    }
}

void command_unsetenv(cargo_t *cg, char **str)
{
    int len = 0;
    int pos = 0;

    for (int i = 0; str[i]; i++)
        len++;
    for (int i = 0; i < len; i++)
        if ((pos = env_getpos(&cg->env_list, str[i])) != -1)
            cg->env_list = env_rm(&cg->env_list, pos);
}

int command_builtin(cargo_t *cg, char **arr)
{
    if (strc(arr[0], "cd")) {
        command_cd(cg, arr);
        return (0);
    }
    if (strc(arr[0], "env") && (arr[1] == NULL || strc(arr[1], ""))) {
        print_env(&cg->env_list, &cg->led);
        return (0);
    }
    if (strc(arr[0], "setenv")) {
        if (!arr[1] || strc(arr[1], "")) print_env(&cg->env_list, &cg->led);
        else command_setenv(cg, arr);
        return (0);
    }
    if (strc(arr[0], "unsetenv")) {
        if (!arr[1])
            cg->led = display_msg(2, "unsetenv: Too few arguments.\n");
        else command_unsetenv(cg, arr);
        return (0);
    }
    return (1);
}