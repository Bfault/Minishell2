/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** error_handling.c
*/

#include "mysh.h"

int check_exec_error(char *path)
{
    struct stat sb;

    stat(path, &sb);
    my_fwr(2, path);
    switch (errno)
    {
        case 8:
            my_fwr(2, ": Exec format error. Wrong Architecture.\n");
            break;
        case 13:
            my_fwr(2, ": Permission denied.\n");
            break;
        case 2:
            my_fwr(2, ": Command not found.\n");
            break;
    }
    return (0);
}