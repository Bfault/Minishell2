/*
** EPITECH PROJECT, 2019
** lib_uni
** File description:
** free_2darr.c
*/

#include "my.h"

void free_2darr(char **arr)
{
    if (arr) {
        for (int i = 0; arr[i]; i++)
            free(arr[i]);
        free(arr);
    }
}