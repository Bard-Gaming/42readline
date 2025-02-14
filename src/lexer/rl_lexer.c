/*
** EPITECH PROJECT, 2024
** Project - 42readline
** File description:
** Implementation for
** rl_lexer_get_lexer,
** rl_lexer_set
*/

#include <readline/lexer.h>


rl_lexer_t *rl_lexer_get_lexer(void)
{
    static rl_lexer_t lexer = {
        .start = "",
        .current = ""
    };

    return &lexer;
}

void rl_lexer_set(const char *src)
{
    rl_lexer_t *lexer = rl_lexer_get_lexer();

    lexer->start = src;
    lexer->current = src;
}
