/*
** EPITECH PROJECT, 2019
** lib
** File description:
** ls_rm.c
*/

#include "lklist.h"
#include "my.h"

lklist_t *ls_rm(lklist_t *ls, int pos)
{
    lklist_t *pre = ls;
    lklist_t *cur = ls;

    if (ls_empty(ls))
        return (0);
    if (pos == 0) {
        ls = ls->next;
        free(cur);
        return (ls);
    }
    for (int i = 0; i < pos; i++) {
        pre = cur;
        cur = cur->next;
    }
    pre->next = cur->next;
    free(cur);
    return (ls);
}