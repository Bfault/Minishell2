/*
** EPITECH PROJECT, 2019
** lib
** File description:
** get_stdin.c
*/

#include "my.h"

char *get_stdin(void)
{
    char ch = 0;
    char *result = NULL;
    int size = 0;

    result = my_malloc(sizeof(char) * 1);
    while ((size = read(0, &ch, 1))) {
        if (ch == '\n')
            return (result);
        result = add_char(result, ch);
    }
    free(result);
    result = my_malloc(sizeof(char) * 5);
    result = my_strdup("exit\0");
    return (result);
}