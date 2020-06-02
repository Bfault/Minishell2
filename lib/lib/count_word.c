/*
** EPITECH PROJECT, 2019
** lib
** File description:
** count_word.c
*/

#include "my.h"

int count_word(char *str, char *exept)
{
    int state = 0;
    unsigned nb = 0;
    char *tmp = NULL;

    for (int i = 0; str[i]; i++) {
        if (char_in_str(exept, tmp = char_to_str(str[i]))) {
            state = 0;
        } else if (state == 0) {
            state = 1;
            ++nb;
        }
        free(tmp);
    }
    return (nb);
}