/*
** EPITECH PROJECT, 2025
** Project - 42readline
** File description:
** Implementation for
** rl_token_delete
*/

#include <readline/token.h>
#include <stdlib.h>


void rl_token_delete(rl_token_t *token)
{
    free(token);
}
