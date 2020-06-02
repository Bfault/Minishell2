/*
** EPITECH PROJECT, 2019
** lib
** File description:
** prefix_del.c
*/

#include "my.h"

char *prefix_del(char *str, char *del)
{
    int len = my_strlen(str);
    int ptr = 0;
    int i = 0;
    int j = 0;
    int delen = my_strlen(del);

    for (; str[j] && del[j]; j++)
        if (str[j] != del[j])
            return (str);
    if (!str[j] && del[j])
        return (str);
    for (i = delen; str[i]; i++, ptr++)
        str[ptr] = str[i];
    len -= delen;
    for (int i = len; str[i]; i++)
        str[i] = 0;
    return (str);
}