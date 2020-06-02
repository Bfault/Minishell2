/*
** EPITECH PROJECT, 2019
** lib
** File description:
** ls_seti.c
*/

#include "lklist.h"
#include "my.h"

void ls_set(lklist_t *ls, void *data, int pos)
{
    if (ls_empty(ls))
        return;
    for (int i = 0; i < pos; i++)
        ls = ls->next;
    ls->data = data;
}