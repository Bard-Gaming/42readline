/*
** EPITECH PROJECT, 2024
** Project - readline
** File description:
** For testing purposes only
*/

#include <readline/lexer.h>
#include <stdio.h>


int main(void)
{
    rl_token_t *current_token;

    rl_lexer_set("   Well hello   \"string test here!\"  there   haha   ");
    current_token = rl_lexer_get_token();
    while (current_token != NULL) {
        printf("%.*s\n", (int)current_token->length, current_token->start);
        current_token = rl_lexer_get_token();
    }
}
