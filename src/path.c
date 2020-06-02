/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** path.c
*/

#include "mysh.h"

char *give_path(env_t *env_list)
{
    int pos = 0;

    pos = env_getpos(&env_list, "PATH");
    if (pos != -1)
        return (env_getvalue(&env_list, pos));
    return (NULL);
}

void fill_path(char **path, char *str)
{
    int move = 0;

    for (int i = 0; path[i]; i++) {
        for (int j = 0; str[move]; j++, move++) {
            if (str[move] == ':') {
                move++;
                break;
            }
            path[i][j] = str[move];
        }
    }
}

char **malloc_path(char **path, char *str)
{
    int len = 0;
    int move = 0;
    int sub_len = 0;

    len = *str ? 1 : 0;
    for (int i = 0; str[i]; i++)
        if (str[i] == ':')
            len++;
    path = my_malloc(sizeof(char *) * (len + 1));
    for (int i = 0; i < len; i++) {
        while (str[move]) {
            move++;
            sub_len++;
        }
        path[i] = my_malloc(sizeof(char) * sub_len + 1);
    }
    return (path);
}

char **parse_path(cargo_t *cg)
{
    char **path = NULL;
    char *str = NULL;

    str = give_path(cg->env_list);
    if (str != NULL) {
        path = malloc_path(path, str);
        fill_path(path, str);
    }
    return (path);
}