/*
** EPITECH PROJECT, 2024
** Project - 42readline
** File description:
** Implementation for
** rl_lexer_get_token
*/

#include <readline/lexer.h>
#include <stdbool.h>
#include <stdlib.h>


static bool is_argument_char(char c)
{
    return
        ('a' <= c && c <= 'z') ||
        ('A' <= c && c <= 'Z') ||
        ('0' <= c && c <= '9') ||
        (c == '_') ||
        (c == '-') ||
        (c == '/') ||
        (c == '.') ||
        (c == ':');
}

static bool is_whitespace(char c)
{
    return
        c == '\n' ||
        c == '\t' ||
        c == ' ';
}

static void skip_whitespace(rl_lexer_t *lexer)
{
    while (*lexer->start != '\0' && is_whitespace(*lexer->start))
        lexer->start++;
    lexer->current = lexer->start;
}

static rl_token_t *get_argument_token(rl_lexer_t *lexer)
{
    rl_token_t *token = malloc(sizeof(rl_token_t));

    if (token == NULL)
        exit(MALLOC_ERROR);
    token->type = RL_TT_ARGUMENT;
    while (*lexer->current != '\0' && is_argument_char(*lexer->current))
        lexer->current++;
    token->start = lexer->start;
    token->length = (lexer->current - lexer->start);
    return token;
}

static rl_token_t *get_argument_string_token(rl_lexer_t *lexer)
{
    rl_token_t *token = malloc(sizeof(rl_token_t));
    char quote = *lexer->start;

    if (token == NULL)
        exit(MALLOC_ERROR);
    token->type = RL_TT_ARGUMENT;
    lexer->start++;
    lexer->current++;
    while (*lexer->current != '\0' && *lexer->current != quote)
        lexer->current++;
    token->start = lexer->start;
    token->length = (lexer->current - 1 - lexer->start);
    lexer->current++;
    return token;
}

static rl_token_t *get_current_token(rl_lexer_t *lexer)
{
    if (is_argument_char(*lexer->start))
        return get_argument_token(lexer);
    if (*lexer->start == '\'' || *lexer->start == '"')
        return get_argument_string_token(lexer);
    return NULL;
}

/*
** Create a token from the lexer's
** current state. Returns NULL if the
** lexer hasn't been initialized or if
** the lexer has reached the end of its source.
*/
rl_token_t *rl_lexer_get_token(void)
{
    rl_lexer_t *lexer = rl_lexer_get_lexer();
    rl_token_t *token;

    if (lexer->start == NULL)
        return NULL;
    skip_whitespace(lexer);
    if (*lexer->start == '\0')
        return NULL;
    token = get_current_token(lexer);
    lexer->start = lexer->current + 1;
    return token;
}
