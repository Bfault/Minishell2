/*
** EPITECH PROJECT, 2019
** lib
** File description:
** replace_in.c
*/

#include "my.h"

char *fix_str(char *str, int pos_start, int pos_end, char *after)
{
    int len_after = my_strlen(after);
    int tmp = 0;

    for (int i = pos_start; after[i - pos_start]; i++)
        str[i] = after[i - pos_start];
    for (tmp = pos_start + len_after; str[pos_end]; tmp++, pos_end++)
        str[tmp] = str[pos_end];
    for (int i = tmp; str[i]; i++)
        str[i] = 0;
    return (str);
}

char *replace_in(char *str, char *before, char *after)
{
    int j = 0;
    int pos_end = -1;
    int pos_start = -1;

    if (my_strlen(before) < my_strlen(after)) return (str);
    for (int i = 0; str[i] && pos_end == -1; i++, j = 0) {
        pos_start++;
        for (j = 0; before[j] && str[i] == before[j]; j++)
            i++;
        if (before[j] == 0)
            pos_end = i;
        else pos_start += j;
    }
    if (pos_end == -1)
        return (str);
    str = fix_str(str, pos_start, pos_end, after);
    return (str);
}