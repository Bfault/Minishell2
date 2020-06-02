/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** get_next_line.c
*/

#include "my.h"

char *ralloc(char *buffer, char *big_buffer, int len, int size)
{
    char *temp = my_malloc(sizeof(char) * len);
    int j = 0;

    for (int i = 0; i < len; i++)
        temp[i] = big_buffer[i];
    free(big_buffer);
    big_buffer = my_malloc(sizeof(char) * len + size + 1);
    for (int i = 0; i < len; i++, j++)
        big_buffer[i] = temp[i];
    for (int i = 0; i < size - 1; i++, j++)
        big_buffer[j] = buffer[i];
    free(temp);
    free(buffer);
    return (big_buffer);
}

char *del_buffer(char *big_buffer, int len)
{
    char *temp;
    int size = my_strlen(big_buffer) - len;
    int j = len + 1;

    temp  = my_malloc(sizeof(char) * size + 1);
    for (int i = 0; i < size + 1; i++, j++)
        temp[i] = big_buffer[j];
    free(big_buffer);
    big_buffer  = my_malloc(sizeof(char) * size + 1);
    for (int i = 0; i < size + 1; i++)
        big_buffer[i] = temp[i];
    free(temp);
    return (big_buffer);
}

char *fill_buffer_gnl(char *big_buffer, char *buffer, int time, int fd)
{
    int size = -1;
    char test = 0;

    if (time == 0 && big_buffer == NULL)
        big_buffer = my_malloc(1 + 1);
    if (big_buffer == NULL) return (NULL);
    buffer = my_malloc(1 + 1);
    if (buffer == 0) return (NULL);
    while ((size = read(fd, buffer, 1)) > 0) {
        test = buffer[size - 1];
        big_buffer = ralloc(buffer, big_buffer, my_strlen(big_buffer), ++size);
        buffer = my_malloc(1 + 1);
        if (test == '\n') break;
    }
    free(buffer);
    if (big_buffer[0] == 0) {
        free(big_buffer);
        return (NULL);
    } else return (big_buffer);
}

char *get_next_line(int fd)
{
    static char *big_buffer;
    static int time = 0;
    char *buffer = NULL;
    int count = 0;

    if (1 <= 0 || fd < 0 || fd > 256) return (NULL);
    big_buffer = fill_buffer_gnl(big_buffer, buffer, time, fd);
    if (big_buffer == NULL) return (NULL);
    while (big_buffer[count] != '\n' && big_buffer[count] != '\0')
        count++;
    buffer = my_malloc(sizeof(char) * count + 1);
    if (buffer == 0) return (NULL);
    for (int i = 0; big_buffer[i] != '\n' && big_buffer[i] != '\0'; i++)
        buffer[i] = big_buffer[i];
    big_buffer = del_buffer(big_buffer, count);
    time = fd != 0 ? 1 : 0;
    return (buffer);
}