/*
** EPITECH PROJECT, 2019
** lib
** File description:
** lklist.h
*/

#ifndef _LKLIST_H_
#define _LKLIST_H_

typedef struct lklist
{
    int index;
    void *data;
    struct lklist *next;
} lklist_t;

#endif