/*
** EPITECH PROJECT, 2019
** lib
** File description:
** ls_add.c
*/

#include "lklist.h"
#include "my.h"

lklist_t *ls_add(lklist_t *ls, void *data, int index, int pos)
{
    lklist_t *pre = ls;
    lklist_t *cur = ls;
    lklist_t *car = ls_create(data, index);

    if (ls_empty(ls))
        return (car);
    if (pos == 0) {
        car->next = ls;
        return (car);
    }
    for (int i = 0; i < pos; i++) {
        pre = cur;
        cur = cur->next;
    }
    pre->next = car;
    car->next = cur;
    return (ls);
}