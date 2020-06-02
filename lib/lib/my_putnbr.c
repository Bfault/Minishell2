/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_putnbr.c
*/

#include "my.h"

void recursive(int nb)
{
    if (nb > 0) {
        recursive(nb / 10);
        my_putchar(nb % 10 + 48);
    }
}

void my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb == 0) {
        my_putchar('0');
        return;
    }
    recursive(nb);
}