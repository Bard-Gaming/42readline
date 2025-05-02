/*
** EPITECH PROJECT, 2025
** Project - 42readline
** File description:
** Implementation for
** readline
*/

#include <readline.h>
#include <readline/buffer.h>
#include <readline/internal.h>
#include <termios.h>
#include <unistd.h>



static bool should_continue(int fd, ssize_t read_len, char c)
{
    if (read_len < 0)
        return false;
    if (isatty(fd) && c == '\n')
        return false;
    if (read_len != 0) {
        return true;
    }
    return false;
}

static char *error(void)
{
    *rl_state_get() = false;
    return NULL;
}

/*
** Empty buffer
** store the first state of the line
** Disable canonical mode
*/
static void setup_readline(struct termios *original)
{
    rl_buffer_empty();
    *rl_state_get() = true;
    disable_canonical_mode(original);
}

char *readline(int fd, const char *prompt)
{
    ssize_t read_len;
    char input;
    struct termios original;

    setup_readline(&original);
    read_len = read(fd, &input, 1);
    if (read_len <= 0)
        return error();
    while (should_continue(fd, read_len, input)) {
        if (handle_special_chars(&input, &read_len, fd))
            continue;
        if (!rl_buffer_add_char(input))
            return error();
        rl_buffer_print(fd, prompt);
        read_len = read(fd, &input, 1);
    }
    *rl_state_get() = false;
    restore_terminal_mode(&original);
    return rl_buffer_get_data();
}
