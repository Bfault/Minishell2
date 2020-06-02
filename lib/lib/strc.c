/*
** EPITECH PROJECT, 2019
** lib_uni
** File description:
** same_word.c
*/

#include "my.h"

int strc(char *str1, char *str2)
{
    while (*str1 && *str2) {
        if (*str1 != *str2) return (0);
        ++str1;
        ++str2;
    }
    if (*str1 != *str2) return (0);
    return (1);
}