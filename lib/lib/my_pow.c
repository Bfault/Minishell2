/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_pow.c
*/

#include "my.h"

int my_pow(int base, int power)
{
    int result = base;

    if (power == 0)
        return (1);
    for (int i = power; i != 1; i--)
        result *= base;
    return (result);
}