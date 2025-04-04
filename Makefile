##
## EPITECH PROJECT, 2024
## salah-eddine
## File description:
## Makefile
##

.PHONY: all clean fclean re unit_tests tests_run coverage

SRC =	src/create_a_shell.c	\
		src/parse_cmd.c	\
		src/handle_signal.c	\
		src/segfault.c	\
		src/shell_commands/env.c	\
		src/shell_commands/set_env.c	\
		src/shell_commands/command_cd.c	\
		src/shell_commands/simple_commands.c	\
		src/shell_commands/other_simple_commands.c	\
		lib/my_putchar.c	\
		lib/my_putstr.c	\
		lib/my_strdup.c	\
		lib/my_strncmp.c	\
		lib/my_str_isnum.c	\
		lib/my_str_isalpha.c	\
		lib/my_strcat.c	\
		lib/my_strcpy.c	\
		lib/my_strncpy.c	\
		lib/printf/my_strlen.c	\
		lib/my_strcmp.c

MAIN =  src/main.c

NAME = mysh

OBJ = $(SRC:.c=.o)

CFLAGS = -I./include -g

TEST_FILES = tests/unit_test_minishell.c

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(MAIN)

unit_tests:
	gcc -o unit_tests $(TEST_FILES) $(SRC) --coverage -lcriterion

tests_run: unit_tests
	./unit_tests

coverage: tests_run
	gcovr --exclude /tests
	gcovr --exclude /tests --txt-metric branch

clean:
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda
	rm -f unit_tests

fclean: clean
	rm -f $(NAME)

re: fclean all
