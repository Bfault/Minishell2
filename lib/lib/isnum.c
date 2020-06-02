/*
** EPITECH PROJECT, 2019
** lib_uni
** File description:
** isnum.c
*/

#include "my.h"

int isnum(char *s)
{
    if (s == NULL || s[0] == 0)
        return (1);
    for (int i = 0; s[i] != 0; i++)
        if (s[i] < '0' || s[i] > '9')
            return (1);
    return (0);
}