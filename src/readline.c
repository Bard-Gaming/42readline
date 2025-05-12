/*
** EPITECH PROJECT, 2025
** Project - 42readline
** File description:
** Implementation for
** readline
*/

#include <42readline.h>
#include <42readline/terminal.h>
#include <42readline/internal.h>
#include <42readline/buffer.h>


char *readline(int fd)
{
    char *result;

    rl_buffer_empty();
    *rl_state_get() = true;
    result = isatty(fd) ?
        rl_terminal_readline(fd) : rl_readline_file(fd);
    *rl_state_get() = false;
    return result;
}
