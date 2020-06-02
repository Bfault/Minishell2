/*
** EPITECH PROJECT, 2019
** lib
** File description:
** char_in_str.c
*/

#include "my.h"

int char_in_str(char *str, char *ch)
{
    for (int j = 0; ch[j]; j++)
        for (int i = 0; str[i]; i++)
            if (str[i] == ch[j])
                return (1);
    return (0);
}