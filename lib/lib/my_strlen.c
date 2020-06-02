/*
** EPITECH PROJECT, 2019
** lib_uni
** File description:
** my_strlen.c
*/

#include "my.h"

int my_strlen(char *str)
{
    return (*str ? 1 + my_strlen(++str) : 0);
}