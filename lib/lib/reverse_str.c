/*
** EPITECH PROJECT, 2019
** lib
** File description:
** reverse_str.c
*/

#include "my.h"

char *reverse_str(char *str)
{
    int len = my_strlen(str) - 1;
    int ptr = 0;
    char tmp = 0;
    int mid = len/2;

    for (int i = len; i > mid; i--, ptr++) {
        tmp = str[ptr];
        str[ptr] = str[i];
        str[i] = tmp;
    }
    return (str);
}