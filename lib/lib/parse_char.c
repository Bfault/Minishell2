/*
** EPITECH PROJECT, 2019
** lib
** File description:
** parse_char.c
*/

#include "my.h"

char **parse_sub_malloc(char *str, char **arr, char *gap, int nb_word)
{
    int count = 0;
    int k = 0;
    char *tmp = NULL;

    for (int i = 0; str[i] != 0; i++, k++, count = 0) {
        while (char_in_str(gap, tmp = char_to_str(str[i])) && str[i] != 0) {
            i++;
            free(tmp);
        }
        free(tmp);
        while (!char_in_str(gap, tmp = char_to_str(str[i])) && str[i] != 0) {
            count++;
            i++;
            free(tmp);
        }
        free(tmp);
        arr[k] = my_malloc(sizeof(char) * (count + 1));
        if (k == nb_word - 1) return (arr);
    }
    return (arr);
}

char **parse_fill_arr(char *str, char **arr, char *gap, int nb_word)
{
    int k = 0;
    int m = 0;
    char *tmp = NULL;

    for (int i = 0; str[i] != 0; i++, k++, m = 0) {
        while (char_in_str(gap, tmp = char_to_str(str[i])) && str[i] != 0) {
            i++;
            free(tmp);
        }
        free(tmp);
        while (!char_in_str(gap, tmp = char_to_str(str[i])) && str[i] != 0) {
            arr[k][m] = str[i];
            i++;
            m++;
            free(tmp);
        }
        free(tmp);
        if (k == nb_word - 1) return (arr);
    }
    return (arr);
}

char **parse_char(char *buff, char *gap)
{
    char **arr = NULL;
    int nb_word = count_word(buff, gap);

    arr = malloc(sizeof(char *) * (nb_word + 1));
    arr[nb_word] = NULL;
    arr = parse_sub_malloc(buff, arr, gap, nb_word);
    arr = parse_fill_arr(buff, arr, gap, nb_word);
    return (arr);
}