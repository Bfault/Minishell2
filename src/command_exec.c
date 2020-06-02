/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** command_exec.c
*/

#include "mysh.h"

int exec_with_path_given(char **arg, char **env)
{
    int stat = 1;
    int led = -1;

    if (fork() == 0) {
        if (execve(arg[0], arg, env) == -1)
            led = check_exec_error(arg[0]);
        exit(1);
    }
    wait(&stat);
    led = (stat == 256) ? 0 : 1;
    check_segfault(stat);
    return (led);
}

int exec_without_path_given(char **arg, char *command, char **env)
{
    int stat = 1;
    int led = 1;

    if (fork() == 0) {
        if (execve(arg[0], arg, env) == -1)
            led = check_exec_error(command);
        exit(1);
    }
    wait(&stat);
    led = (stat == 256) ? 0 : 1;
    check_segfault(stat);
    return (led);
}

int child_process(char *command, char **arg, char **env, char **path)
{
    int path_pow = 0;
    int i = 0;
    int led = -1;
    struct stat sb;

    for (int i = 0; arg[0][i] && !path_pow; i++)
        if (arg[0][i] == '/')
            path_pow = 1;
    if (path_pow == 1)
        led = exec_with_path_given(arg, env);
    else {
        for (; path && path[i]; i++) {
            free(arg[0]);
            arg[0] = fusion_word(path[i], "/", command, NULL);
            if (stat(arg[0], &sb) != -1) break;
        }
        led = exec_without_path_given(arg, command, env);
    }
    return (led);
}

char *remove_path(char *str)
{
    char *result = NULL;
    int tmp = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == '/')
            tmp = i;
    result = my_malloc(sizeof(char) * my_strlen(str) - tmp + 1);
    for (int i = 0; str[tmp]; i++, tmp++)
        result[i] = str[tmp];
    return (result);
}

int command_exec(cargo_t *cg, char **arr)
{
    char *command = NULL;
    char **path = NULL;

    if (strc(arr[0], ""))
        return (1);
    path = parse_path(cg);
    command = remove_path(arr[0]);
    cg->led = child_process(command, arr, cg->envp, path);
    free(command);
    for (int i = 0; path[i]; i++)
        free(path[i]);
    free(path);
    return (1);
}