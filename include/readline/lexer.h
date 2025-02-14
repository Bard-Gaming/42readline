/*
** EPITECH PROJECT, 2024
** Project - 42readline
** File description:
** Header file for all things
** related to the lexer
*/

#ifndef RL_LEXER_H
    #define RL_LEXER_H
    #include <readline/types.h>
    #include <stddef.h>


struct rl_lexer {
    const char *start;
    const char *current;
};


enum rl_token_type {
    RL_TT_ARGUMENT,       // ex: 42; "42"
    RL_TT_VARIABLE,    // ex: $VAR; $PATH
};


struct rl_token {
    rl_token_type_t type;
    const char *start;
    size_t length;
};


// Setup:
void rl_lexer_set(const char *src);

// Continuous use:
rl_token_t *rl_lexer_get_token(void);

// These shouldn't be used by an end-user:
rl_lexer_t *rl_lexer_get_lexer(void);


#endif
