/*
** EPITECH PROJECT, 2025
** Project - 42readline
** File description:
** Implementation for
** rl_token_print
*/

#include <readline/token.h>
#include <unistd.h>


/*
** This should be used for debug only.
** As such, it is not optimized (i.e.
** there is no attempt made to reduce
** the number of syscalls).
*/
void rl_token_print(const rl_token_t *token)
{
    char tt_char = token->type + '0';

    write(STDIN_FILENO, "Token: \"", 8);
    write(STDIN_FILENO, token->value, token->length);
    write(STDIN_FILENO, "\"; ID: ", 7);
    write(STDIN_FILENO, &tt_char, 1);
}
