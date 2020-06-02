/*
** EPITECH PROJECT, 2019
** lib
** File description:
** ls_geti.c
*/

#include "lklist.h"
#include "my.h"

void *ls_get(lklist_t *ls, int pos)
{
    if (ls_empty(ls))
        return (0);
    for (int i = 0; i < pos; i++)
        ls = ls->next;
    return (ls->data);
}