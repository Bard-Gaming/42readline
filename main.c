/*
** EPITECH PROJECT, 2024
** Project - readline
** File description:
** For testing purposes only
*/

#include <readline/lexer.h>
#include <readline/token.h>
#include <stdio.h>


int main(void)
{
    rl_token_t *token;

    rl_lexer_set_source(stdin);
    token = rl_lexer_get_token();
    while (token != NULL) {
        rl_token_print(token);
        token = rl_lexer_get_token();
    }
    return 0;
}
