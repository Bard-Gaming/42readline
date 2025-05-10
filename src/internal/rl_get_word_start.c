/*
** EPITECH PROJECT, 2025
** Project - 42readline
** File description:
** Implementation for
** rl_get_word_start
*/

#include <readline/internal.h>


/*
** Retrieves a pointer to the start of the selected
** word in the input buffer.
*/
char *rl_get_word_start(const char *input, size_t index)
{
    while (index > 0 && rl_is_word_char(input[index]))
        index--;
    return (char *)(input + index);
}
