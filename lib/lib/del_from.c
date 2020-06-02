/*
** EPITECH PROJECT, 2019
** lib
** File description:
** del_from.c
*/

#include "my.h"

char *del_from(char *str, char *del)
{
    int ptr = 0;
    int pos = -1;

    for (int i = 0; pos == -1 && str[i]; i++) {
        for (ptr = 0; del[ptr] && str[i] == del[ptr]; ptr++)
            i++;
        if (del[ptr] == 0)
            pos = i - ptr;
    }
    if (pos != -1)
        for (int i = pos; str[i]; i++)
            str[i] = 0;
    return (str);
}