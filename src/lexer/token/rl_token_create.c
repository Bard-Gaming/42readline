/*
** EPITECH PROJECT, 2025
** Project - 42readline
** File description:
** Implementation for
** rl_token_create
*/

#include <readline/token.h>
#include <stdlib.h>


/*
** TODO: Remove this and use real strdup
** when allowed
*/
static char *rl_strdup(const char *ref, size_t len)
{
    char *duplicate = malloc((len + 1) * sizeof(char));

    if (duplicate == NULL)
        return NULL;
    for (size_t i = 0; i < len; i++)
        duplicate[i] = ref[i];
    duplicate[len] = '\0';
    return duplicate;
}

/*
** Small utility for creating a token with
** given values. Returns NULL on error.
*/
rl_token_t *rl_token_create(rl_token_type_t type, const char *val, size_t len)
{
    rl_token_t *token = malloc(sizeof(rl_token_t));

    if (token == NULL)
        return NULL;
    token->value = rl_strdup(val, len);
    if (token->value == NULL) {
        free(token);
        return NULL;
    }
    token->type = type;
    token->length = len;
    return token;
}
