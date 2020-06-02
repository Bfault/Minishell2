/*
** EPITECH PROJECT, 2019
** lib_uni
** File description:
** error.c
*/

#include "my.h"

int error_msg(int return_value, char *str)
{
    write(0, RED_BRIGHT, 6);
    write(2, str, my_strlen(str));
    write(0, NORMAL_BRIGHT, 7);
    return (return_value);
}
