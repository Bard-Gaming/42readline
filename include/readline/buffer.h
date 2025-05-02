/*
** EPITECH PROJECT, 2025
** Project - 42readline
** File description:
** Header file for readline's
** internal string buffer
*/

#ifndef LIB_READLINE_BUFFER_H
    #define LIB_READLINE_BUFFER_H

    #define INITIAL_BUFFER_SIZE (1 << 7)
    #define CLEAR_LINE "\33[2K\r"

    #include <stddef.h>
    #include <stdbool.h>


typedef struct {
    char *data;
    size_t count;
    size_t capacity;
    int arrow_index;
} string_buffer_t;

bool cut_buffer(void);

bool rl_buffer_add_char(char c);
void rl_buffer_empty(void);
string_buffer_t *rl_buffer_get(void);
char *rl_buffer_get_data(void);
void rl_buffer_print(int fd, const char *prompt);

#endif
