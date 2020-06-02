/*
** EPITECH PROJECT, 2019
** lib
** File description:
** ls_free.c
*/

#include "lklist.h"
#include "my.h"

lklist_t *ls_free(lklist_t *ls)
{
    lklist_t *tmp = NULL;

    while (ls) {
        tmp = ls->next;
        free(ls);
        ls = tmp;
    }
    return (ls);
}