/*
** EPITECH PROJECT, 2025
** Project - 42readline
** File description:
** Implementation for
** readline
*/

#include <readline.h>
#include <stddef.h>
#include <stdio.h>


char *readline(FILE *stream)
{
    char *result = NULL;
    size_t buffer_capacity = 0;
    ssize_t read_len;

    read_len = getline(&result, &buffer_capacity, stream);
    if (read_len <= 0)
        return NULL;
    return result;
}
