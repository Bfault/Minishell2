/*
** EPITECH PROJECT, 2019
** lib
** File description:
** fusion_word.c
*/

#include "my.h"

char *fusion_word(char *str, ...)
{
    va_list lt;
    char *result = NULL;
    char *test = str;
    int len = 0;
    int ptr = 0;

    va_start(lt, str);
    do {
        len += my_strlen(test);
    } while ((test = va_arg(lt, char *)) != NULL);
    va_end(lt);
    result = my_malloc(len + 1);
    va_start(lt, str);
    test = str;
    do {
        for (int i = 0; test[i]; i++, ptr++)
            result[ptr] = test[i];
    } while ((test = va_arg(lt, char *)) != NULL);
    va_end(lt);
    return (result);
}