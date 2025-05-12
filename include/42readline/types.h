/*
** EPITECH PROJECT, 2025
** Project - 42readline
** File description:
** Header file for all common
** types of the library
*/

#ifndef LIB_READLINE_TYPES_H
    #define LIB_READLINE_TYPES_H
    #include <stdbool.h>
    #include <stddef.h>

    #define UNUSED __attribute__((unused))

/* --------- Common functions -------- */
typedef char *(*autocomplete_fnc_t)(const char *);
typedef void (*long_autocomplete_fnc_t)(const char *);
typedef char *(*history_fnc_t)(size_t);


#endif
