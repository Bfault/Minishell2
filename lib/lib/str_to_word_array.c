/*
** EPITECH PROJECT, 2019
** lib_uni
** File description:
** str_to_word_array.c
*/

#include "my.h"

char **sub_count(char *str, char **arr, int nb_word)
{
    int count = 0;
    int k = 0;

    for (int i = 0; str[i] != 0; i++, k++, count = 0) {
        while ((str[i] == 32 || str[i] == '\t') && str[i] != 0)
            i++;
        while (str[i] != 32 && str[i] != '\t' && str[i] != 0) {
            count++;
            i++;
        }
        arr[k] = my_malloc(sizeof(char) * count + 1);
        arr[k][count] = 0;
        if (k == nb_word - 1)
            return (arr);
    }
    return (arr);
}

char **fill_arr(char *str, char **arr,  int nb_word)
{
    int k = 0;
    int m = 0;

    for (int i = 0; str[i] != 0; i++, k++, m = 0) {
        while ((str[i] == 32 || str[i] == '\t') && str[i] != 0) {
            i++;
        }
        while (str[i] != 32 && str[i] != '\t' && str[i] != 0) {
            arr[k][m] = str[i];
            i++;
            m++;
        }
        if (k == nb_word - 1)
            return (arr);
    }
    return (arr);
}

char **str_to_word_array(char *str)
{
    char **arr = NULL;
    int nb_word = 0;

    nb_word = count_word(str, " \n\t");
    arr = malloc(sizeof(char *) * (nb_word + 1));
    arr[nb_word] = NULL;
    arr = sub_count(str, arr, nb_word);
    arr = fill_arr(str, arr, nb_word);
    return (arr);
}