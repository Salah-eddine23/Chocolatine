#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/protos_shell.h"
#include "../include/protos_lib.h"

void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(test_my_strdup, test_my_strdup_long_string, .init = redirect_all_std)
{
    char *dup = my_strdup("Coucou AER");
    cr_assert_str_eq(dup, "Coucou AER");
    free(dup);
}
Test(minishell_lib_test, test01, .init = redirect_all_std)
{
    my_putstr("I like the minishell!");
    cr_assert_stdout_eq_str("I like the minishell!");
}

Test(minishell_lib_test, test02, .init = redirect_all_std)
{
    int length = my_strlen("lol");

    cr_assert_eq(length, 3);
}

Test(minishell_lib_test, test04, .init = redirect_all_std)
{
    char dest[20] = "Hello";

    my_strcat(dest, " World");
    cr_assert_str_eq(dest, "Hello World");
}

Test(minishell, test05, .init = redirect_all_std)
{
    int return_value = my_str_isalpha("Bonjour");

    cr_assert_eq(return_value, 0);
}

Test(minishell_lib_test, test08, .init = redirect_all_std)
{
    my_putstr("");
    cr_assert_stdout_eq_str("");
}

Test(minishell, test08, .init = redirect_all_std)
{
    int return_value = my_str_isalpha("Bonjour AER , si tu regardes ça , c'est parce que j'ai fais des units-tests :PPPP292292929");

    cr_assert_eq(return_value, 84);
}

Test(minishell, test09, .init = redirect_all_std)
{
    int return_value = my_str_isnum("292992");

    cr_assert_eq(return_value, 0);
}

Test(test_my_strcpy, test10, .init = redirect_all_std)
{
    char dest[20];

    my_strcpy(dest, "Hello");
    cr_assert_str_eq(dest, "Hello");
}

Test(test_my_strcpy, test11, .init = redirect_all_std)
{
    char dest[20];

    my_strcpy(dest, "");
    cr_assert_str_eq(dest, "");
}

Test(test_my_strcpy, test12, .init = redirect_all_std)
{
    char dest[20];

    my_strcpy(dest, "12345");
    cr_assert_str_eq(dest, "12345");
}

Test(test_my_strdup, test13, .init = redirect_all_std)
{
    char *dup = my_strdup("Hello");

    cr_assert_str_eq(dup, "Hello");
    free(dup);
}

Test(test_my_strdup, test14, .init = redirect_all_std)
{
    char *dup = my_strdup("");

    cr_assert_str_eq(dup, "");
    free(dup);
}

Test(test_my_strdup, test15, .init = redirect_all_std)
{
    char *dup = my_strdup("12345");

    cr_assert_str_eq(dup, "12345");
    free(dup);
}

Test(test_my_strcat, test16, .init = redirect_all_std)
{
    char dest[20] = "Hello";

    my_strcat(dest, " World");
    cr_assert_str_eq(dest, "Hello World");
}

Test(test_my_strcat, test17, .init = redirect_all_std)
{
    char dest[20] = "";

    my_strcat(dest, "Hello");
    cr_assert_str_eq(dest, "Hello");
}

Test(test_my_strcat, test18, .init = redirect_all_std)
{
    char dest[20] = "Hello";

    my_strcat(dest, "");
    cr_assert_str_eq(dest, "Hello");
}

Test(minishell, test_my_str_isalpha_empty, .init = redirect_all_std)
{
    int return_value = my_str_isalpha("");
    cr_assert_eq(return_value, 0);
}

Test(minishell, test_my_str_isalpha_special_chars, .init = redirect_all_std)
{
    int return_value = my_str_isalpha("Hello!");
    cr_assert_eq(return_value, 84);
}

Test(minishell, test_my_str_isnum_mixed_chars, .init = redirect_all_std)
{
    int return_value = my_str_isnum("123abc");
    cr_assert_eq(return_value, 84);
}

Test(minishell, test_my_str_isnum_with_spaces, .init = redirect_all_std)
{
    int return_value = my_str_isnum("123 456");
    cr_assert_eq(return_value, 84);
}


Test(minishell_lib_test, my_putstr_basic, .init = redirect_all_std)
{
    my_putstr("Hello");
    cr_assert_stdout_eq_str("Hello");
}

Test(minishell_lib_test, my_putstr_empty, .init = redirect_all_std)
{
    my_putstr("");
    cr_assert_stdout_eq_str("");
}

Test(minishell_lib_test, my_putstr_special_chars, .init = redirect_all_std)
{
    my_putstr("Hello\nWorld\t!");
    cr_assert_stdout_eq_str("Hello\nWorld\t!");
}

Test(minishell_lib_test, my_putstr_numeric, .init = redirect_all_std)
{
    my_putstr("1234567890");
    cr_assert_stdout_eq_str("1234567890");
}

Test(minishell_lib_test, my_strncmp_identical, .init = redirect_all_std)
{
    int result = my_strncmp("Hello", "Hello", 5);
    cr_assert_eq(result, 0);
}

Test(minishell_lib_test, my_strncmp_different, .init = redirect_all_std)
{
    int result = my_strncmp("Hello", "World", 5);
    cr_assert_neq(result, 0);
}

Test(minishell_lib_test, my_strncmp_partial_match, .init = redirect_all_std)
{
    int result = my_strncmp("Hello", "Helly", 3);
    cr_assert_eq(result, 0);
}

Test(minishell_lib_test, my_strncmp_longer_n, .init = redirect_all_std)
{
    int result = my_strncmp("Hello", "Hellz", 10);
    cr_assert_neq(result, 0);
}

Test(minishell_lib_test, my_strncmp_empty_string, .init = redirect_all_std)
{
    int result = my_strncmp("", "Hello", 5);
    cr_assert_neq(result, 0);
}

Test(minishell_lib_test, my_strncmp_both_empty, .init = redirect_all_std)
{
    int result = my_strncmp("", "", 5);
    cr_assert_eq(result, 0);
}
