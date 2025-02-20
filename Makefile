##
## EPITECH PROJECT, 2024
## Project - readline
## File description:
## Makefile used to help
## and facilitate the compilation
## of the readline library
##

CC = gcc
CFLAGS =

NAME = libreadline.a

INCLUDE_DIRS = -I./include

SRC_FILES =	src/readline.c						\

OBJ_FILES = $(notdir $(SRC_FILES:%.c=%.o))

.PHONY = all debug clean fclean re

all: $(NAME)

$(NAME):
	@$(CC) -c $(SRC_FILES) $(CFLAGS) $(INCLUDE_DIRS)
	@ar rc $(NAME) $(OBJ_FILES)

debug: CFLAGS += -ggdb -Wall -Wextra
debug: fclean $(NAME)

clean:
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
