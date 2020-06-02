/*
** EPITECH PROJECT, 2019
** lib_uni
** File description:
** my_atoi.c
*/

#include "my.h"

int my_atoi(char *str)
{
    int less = 0;
    int result = 0;

    if (str == NULL)
        return (0);
    less = str[0] == '-' ? 1 : 0;
    for (int i = less; str[i] != 0; i++)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    for (int i = less; str[i] != 0; i++)
        result = i != less ? result * 10 + str[i] - 48 : str[i] - 48;
    return (less ? result * -1 : result);
}