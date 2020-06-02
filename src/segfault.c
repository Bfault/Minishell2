/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** segfault.c
*/

#include "mysh.h"

void check_segfault(int stat)
{
    if (WIFSIGNALED(stat)) {
        my_fwr(2, "Segmentation fault");
        if (WCOREDUMP(stat))
            my_fwr(2, " (core dumped)\n");
        else my_fwr(2, "\n");
    }
    if (SIGFPE == stat) {
        my_fwr(2, "Floating exception");
        if (WCOREDUMP(stat))
            my_fwr(2, " (core dumped)\n");
        else my_fwr(2, "\n");
    }
}
