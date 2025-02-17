/*
** EPITECH PROJECT, 2025
** Project - 42readline
** File description:
** Header file for lexer
** tokens
*/

#ifndef RL_TOKEN_H
    #define RL_TOKEN_H
    #include <readline/types.h>
    #include <stddef.h>


enum rl_token_type {
    RL_TT_ARGUMENT,  // Arguments (includes strings)
    RL_TT_VARIABLE,  // Variable identifiers (to be replaced by values)
};


struct rl_token {
    rl_token_type_t type;
    char *value;
    size_t length;
};


rl_token_t *rl_token_create(rl_token_type_t type, const char *val, size_t len);
void rl_token_delete(rl_token_t *token);
void rl_token_print(const rl_token_t *token);


#endif
