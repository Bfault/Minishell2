/*
** EPITECH PROJECT, 2019
** lib_uni
** File description:
** malloc_str.c
*/

#include "my.h"

void *my_malloc(int len)
{
    char *str = 0;

    str = malloc(len);
    if (!(str))
        return (NULL);
    for (int i = 0; i < len; i++)
        str[i] = 0;
    return (str);
}