/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** engine_process.c
*/

#include "mysh.h"
#include "my.h"

void free_commands(char ***commands)
{
    for (int i = 0; commands[i]; i++)
        for (int j = 0; commands[i][j]; j++)
            free(commands[i][j]);
    for (int i = 0; commands[i]; i++)
        free(commands[i]);
    free(commands);
}

char ***parse_commands(char *buff)
{
    char ***commands = NULL;
    char **arr = NULL;
    int len = 0;

    arr = parse_char(buff, ";");
    while (arr[len])
        len++;
    commands = malloc(sizeof(char **) * (len + 1));
    commands[len] = NULL;
    for (int i = 0; arr[i]; i++)
        commands[i] = parse_char(arr[i], " \n\t");
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
    return (commands);
}

int engine_process(cargo_t *cg, char *buff)
{
    int test = 0;
    char ***commands = NULL;

    if (!(*buff)) return (0);
    commands = parse_commands(buff);
    for (int i = 0; commands[i]; i++) {
        test = command_builtin(cg, commands[i]);
        update_env(cg);
        if (test)
            command_exec(cg, commands[i]);
    }
    free_commands(commands);
    return (0);
}