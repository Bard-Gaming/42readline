/*
** EPITECH PROJECT, 2025
** Project - 42sh
** File description:
** Implementation for
** rl_buffer_set_history
*/

#include <readline/buffer.h>
#include <stdlib.h>


static void reset_buffer(string_buffer_t *buffer)
{
    if (buffer->count == 0)
        return;
    buffer->count = 0;
    buffer->arrow_index = 0;
    buffer->data[0] = '\0';
}

/*
** Sets the buffer to the command in
** history at the index specified
** in the buffer.
*/
void rl_buffer_set_history(void)
{
    string_buffer_t *buffer = rl_buffer_get();
    char *history = buffer->history(buffer->history_index);
    size_t len;

    if (history == NULL)
        return;
    reset_buffer(buffer);
    for (len = 0; history[len] != '\0'; len++)
        rl_buffer_add_char(history[len]);
    buffer->arrow_index = len;
    free(history);
}
