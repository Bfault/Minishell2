/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** cd.c
*/

#include "mysh.h"

char *old_pwd_update(env_t *env_list, int choice)
{
    int pos = 0;

    pos = env_getpos(&env_list, "OLD_PWD");
    if (pos != -1) {
        if (choice == 0)
            return (env_getvalue(&env_list, pos));
        env_modify(&env_list, getcwd(NULL, 0), pos);
    }
    return ("/");
}

char *get_home(env_t *env_list)
{
    int pos = 0;

    pos = env_getpos(&env_list, "HOME");
    return ((pos != -1) ? env_getvalue(&env_list, pos) : "/");
}

void pwd_update(env_t *env_list)
{
    int pos = 0;

    pos = env_getpos(&env_list, "PWD");
    if (pos != -1)
        env_modify(&env_list, getcwd(NULL, 0), pos);
}

void command_cd(cargo_t *cg, char **arr)
{
    char *path = NULL;
    char *tmp = NULL;

    tmp = old_pwd_update(cg->env_list, 0);
    old_pwd_update(cg->env_list, 1);
    if (!arr[1])
        path = get_home(cg->env_list);
    else if (strc(arr[1], "-")) {
        path = tmp;
    } else
        path = arr[1];
    if (chdir(path) == -1) {
        display_cd_error(cg, path);
    }
    pwd_update(cg->env_list);
}