/*
** EPITECH PROJECT, 2019
** lib
** File description:
** alphanumeric.c
*/

#include "my.h"

int check_excption(char *str, int i, char execption, ...)
{
    va_list lt;
    char test = 0;

    test = execption;
    va_start(lt, execption);
    do {
        if (str[i] == test) {
            return (0);
            break;
        }
    } while ((test = va_arg(lt, int)));
    va_end(lt);
    return (1);
}

int alphanumeric(char *str, char execption, ...)
{
    for (int i = 0; str[i]; i++)
        if (!(str[i] >= 48 && str[i] <= 57) && !(str[i] >= 65 && str[i] <= 90)
        && !(str[i] >= 97 && str[i] <= 122))
            if (check_excption(str, i, execption))
                return (1);
    return (0);
}