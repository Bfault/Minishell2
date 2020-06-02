/*
** EPITECH PROJECT, 2019
** lib
** File description:
** word_array_to_str.c
*/

#include "my.h"

char *word_array_to_str(char **arr)
{
    char *str = NULL;
    int len = 0;

    for (int i = 0; arr[i] != NULL; i++, len++)
        for (int j = 0; arr[i][j]; j++, len++);
    str = my_malloc(sizeof(char) * len);
    len = 0;
    for (int i = 0; arr[i]; i++, len++) {
        for (int j = 0; arr[i][j]; j++, len++)
            str[len] = arr[i][j];
        if (arr[i + 1] != NULL)
            str[len] = ' ';
    }
    return (str);
}