/*
** EPITECH PROJECT, 2019
** lib_uni
** File description:
** my_free.c
*/

#include "my.h"

void *my_free(void *str)
{
    if (str != NULL)
        free(str);
    else
        return (NULL);
    return (str);
}