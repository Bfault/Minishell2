/*
** EPITECH PROJECT, 2019
** lib
** File description:
** add_char.c
*/

#include "my.h"

char *add_char(char *str, char ch)
{
    int len = my_strlen(str);
    char tmp[len];

    for (int i = 0; str[i]; i++)
        tmp[i] = str[i];
    tmp[len] = 0;
    free(str);
    str = my_malloc(sizeof(char) * (len + 2));
    for (int i = 0; tmp[i]; i++)
        str[i] = tmp[i];
    str[len] = ch;
    return (str);
}