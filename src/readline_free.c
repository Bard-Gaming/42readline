/*
** EPITECH PROJECT, 2025
** Project - 42readline
** File description:
** Implementation for
** readline_free
*/

#include <42readline.h>
#include <42readline/buffer.h>
#include <stdlib.h>


void readline_free(void)
{
    string_buffer_t *buffer = rl_buffer_get();

    free(buffer->data);
}
