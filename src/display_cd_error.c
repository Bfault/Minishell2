/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** display_cd_error.c
*/

#include "mysh.h"

void display_cd_error(cargo_t *cg, char *path)
{
    display_msg(2, path);
    if (errno == 13)
        cg->led = display_msg(2, ": Permission denied.\n");
    else if (errno == 2 && access(path, F_OK) != 0)
        cg->led = display_msg(2, ": No such file or directory.\n");
    else
        cg->led = display_msg(2, ": Not a directory.\n");
}