/*
** EPITECH PROJECT, 2019
** lib
** File description:
** char_to_str.c
*/

#include "my.h"

char *char_to_str(char c)
{
    char *result = my_malloc(sizeof(char) * 2);

    result[0] = c;
    result[1] = 0;
    return (result);
}