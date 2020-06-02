/*
** EPITECH PROJECT, 2019
** lib
** File description:
** absolute.c
*/

#include "my.h"

int absolute(int nb)
{
    return ((nb < 0) ? -nb : nb);
}