/*
** EPITECH PROJECT, 2025
** Project - 42readline
** File description:
** Header file for internal
** library functions
*/

#ifndef LIB_READLINE_INTERNAL_H
    #define LIB_READLINE_INTERNAL_H
    #include <stdbool.h>

    #define CHAR_DEL 127


bool *rl_state_get(void);

/*
** Disable and enable terminal mode
** to stop tabs and arrows
*/
void disable_canonical_mode(struct termios *original);
void restore_terminal_mode(struct termios *original);

/*
** Handle characters like arrows and tab
*/
int handle_special_chars(char *input, ssize_t *read_len, int fd);


#endif
