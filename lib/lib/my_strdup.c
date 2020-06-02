/*
** EPITECH PROJECT, 2019
** lib_uni
** File description:
** my_strdup.c
*/

#include "my.h"

char *my_strdup(char *str)
{
    int len = my_strlen(str) + 1;
    char *tmp = my_malloc(sizeof(char) * len);

    for (int i = 0; i < len; i++)
        tmp[i] = str[i];
    return (tmp);
}