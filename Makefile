##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile for printf
##

SRC		=		my_putchar.c \
				my_putstr.c	\
				my_strlen.c	\
				initial_check.c	\
				my_put_double.c	\
				my_printf.c	\
                my_put_base_l.c \
                my_put_base_h.c \
				my_put_base.c \
				my_put_nbr.c \
				my_strdup.c \
				check_is_flag.c	\
		        check_is_specifier.c \
				check_is_len.c \
				check_is_element.c \
				my_revstr.c \
                skip_over.c \
                my_to_science.c \
                add_str.c \
                flag_g.c \
                get_elements.c \
                look_for_precision.c \
                num_size.c \
                printf_flags/add_address.c \
                printf_flags/build_buffer.c \
                printf_flags/flag_cap_g.c \
                printf_flags/flag_cap_x.c \
                printf_flags/flag_cap_e.c \
                printf_flags/flag_cap_f.c \
                printf_flags/flag_e.c \
                printf_flags/flag_g1.c \
                printf_flags/flag_x.c \
                printf_flags/flag_u.c \
                printf_flags/flag_o.c \
                printf_flags/flag_s.c \
                printf_flags/flag_percent.c \
                printf_flags/flag_d.c \
                printf_flags/flag_f.c \
                printf_flags/flag_i.c \
                printf_flags/flag_c.c \
                printf_flags/flag_p.c

MAIN    =       main.c

OBJ		=		$(SRC:.c=.o)

FLAGS   =       -lcriterion --coverage -L. libmy.a

NAME	=		libmy.a

TEST_OUT =		unit-test

TEST_FILES	=	tests/test_my_printf.c

SRC_TESTS	=   my_printf.c

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f $(TEST_OUT)

clean_test: fclean
	find -name "*gcno" -delete
	find -name "*gcda" -delete

tests_run: fclean all
	gcc -o $(TEST_OUT) $(SRC) $(TEST_FILES) $(FLAGS)
	./$(TEST_OUT)

re: fclean all
