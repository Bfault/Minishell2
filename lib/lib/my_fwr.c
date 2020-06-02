/*
** EPITECH PROJECT, 2019
** lib_uni
** File description:
** my_fwr.c
*/

#include "my.h"

int my_strlen(char *);

void my_fwr(int flux, char * msg)
{
    write(flux, msg, my_strlen(msg));
}