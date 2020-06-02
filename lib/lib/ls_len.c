/*
** EPITECH PROJECT, 2019
** lib
** File description:
** ls_len.c
*/

#include "lklist.h"
#include "my.h"

size_t ls_len(lklist_t *ls)
{
    return (ls ? 1 + ls_len(ls = ls->next) : 0);
}