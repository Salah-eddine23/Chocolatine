/*
** EPITECH PROJECT, 2024
** test_my_printf
** File description:
** tests the function my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "../include/protos.h"
#include <stdlib.h>

int my_printf(char const *format, ...);

void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(my_printf, std_print, .init = redirect_all_std)
{
	my_printf("hello world");
	cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, std_string_space, .init = redirect_all_std)
{
    my_printf("%s", " ");
    cr_assert_stdout_eq_str(" ");
}

Test(my_printf, std_string_null, .init = redirect_all_std)
{
    my_printf("%s", " ");
    cr_assert_stdout_eq_str(" ");
}

Test(my_printf, std_flag_g_science_pos, .init = redirect_all_std)
{
    my_printf("hello %g", 0.0000045);
    cr_assert_stdout_eq_str("hello 4.5e-06");
}

Test(my_printf, std_flag_G_science_neg1, .init = redirect_all_std)
{
    my_printf("%G", -5.600);
    cr_assert_stdout_eq_str("-5.6");
}

Test(my_printf, std_string_int, .init = redirect_all_std)
{
    my_printf("%s", "2");
    cr_assert_stdout_eq_str("2");
}

Test(my_printf, std_string_neg_int, .init = redirect_all_std)
{
    my_printf("%s", "-2");
    cr_assert_stdout_eq_str("-2");
}

Test(my_printf, std_string, .init = redirect_all_std)
{
    my_printf("hello %s", "World");
    cr_assert_stdout_eq_str("hello World");
}

Test(my_printf, std_neg_digit, .init = redirect_all_std)
{
    my_printf("hello %d", -45);
    cr_assert_stdout_eq_str("hello -45");
}

Test(my_printf, std_big_digit, .init = redirect_all_std)
{
    my_printf("hello %d", 452222);
    cr_assert_stdout_eq_str("hello 452222");
}

Test(my_printf, std_big_neg_digit, .init = redirect_all_std)
{
    my_printf("eddy le shlag %d", -22222245);
    cr_assert_stdout_eq_str("eddy le shlag -22222245");
}

Test(my_printf, std_double_digit, .init = redirect_all_std)
{
    my_printf("10 %d", 45);
    cr_assert_stdout_eq_str("10 45");
}

Test(my_printf, std_double_neg_digit, .init = redirect_all_std)
{
    my_printf("-2 %d", -45);
    cr_assert_stdout_eq_str("-2 -45");
}

Test(my_printf, std_null_neg_digit, .init = redirect_all_std)
{
    my_printf(" %d", -45);
    cr_assert_stdout_eq_str(" -45");
}

Test(my_printf, std_double_pos_digit, .init = redirect_all_std)
{
    my_printf(" %d", 45);
    cr_assert_stdout_eq_str(" 45");
}

Test(my_printf, std_digit, .init = redirect_all_std)
{
    my_printf("hello %d", 45);
    cr_assert_stdout_eq_str("hello 45");
}

Test(my_printf, std_double_null_digit, .init = redirect_all_std)
{
    my_printf(" %d", 0);
    cr_assert_stdout_eq_str(" 0");
}

Test(my_printf, std_char_spe_carac, .init = redirect_all_std)
{
    my_printf("hello %  c", '%');
    cr_assert_stdout_eq_str("hello %");
}

Test(my_printf, std_char_space, .init = redirect_all_std)
{
    my_printf("hello %  c", 'n');
    cr_assert_stdout_eq_str("hello n");
}

Test(my_printf, std_char_ascii, .init = redirect_all_std)
{
    my_printf("hello %  c", 49);
    cr_assert_stdout_eq_str("hello 1");
}

Test(my_printf, std_char_ascii_min, .init = redirect_all_std)
{
    my_printf("hello %  c", 122);
    cr_assert_stdout_eq_str("hello z");
}

Test(my_printf, std_char_alpha, .init = redirect_all_std)
{
    my_printf("hello %  c", 85);
    cr_assert_stdout_eq_str("hello U");
}

Test(my_printf, std_char, .init = redirect_all_std)
{
    my_printf("hello %c", 'u');
    cr_assert_stdout_eq_str("hello u");
}

Test(my_printf, std_char_precent, .init = redirect_all_std)
{
    my_printf("hello %%");
    cr_assert_stdout_eq_str("hello %");
}

Test(my_printf, std_percent_string, .init = redirect_all_std)
{
    my_printf("hello %s", "%");
    cr_assert_stdout_eq_str("hello %");
}

Test(my_printf, std_integer, .init = redirect_all_std)
{
    my_printf("hello %i", 67);
    cr_assert_stdout_eq_str("hello 67");
}

Test(my_printf, std_unsigned, .init = redirect_all_std)
{
    my_printf("hello %u", 127);
    cr_assert_stdout_eq_str("hello 127");
}

Test(my_printf, std_hexa, .init = redirect_all_std)
{
    my_printf("hello %x", 127);
    cr_assert_stdout_eq_str("hello 7f");
}

Test(my_printf, std_capital_hexa, .init = redirect_all_std)
{
    my_printf("hello %X", 127);
    cr_assert_stdout_eq_str("hello 7F");
}

Test(my_printf, std_capital_octa, .init = redirect_all_std)
{
    my_printf("hello %o", 43);
    cr_assert_stdout_eq_str("hello 53");
}

Test(my_printf, std_unsigned_negative, .init = redirect_all_std)
{
    my_printf("hello %u", -5);
    cr_assert_stdout_eq_str("hello 4294967291");
}

Test(my_printf, std_hexa_negative, .init = redirect_all_std)
{
    my_printf("hello %x", -5);
    cr_assert_stdout_eq_str("hello fffffffb");
}

Test(my_printf, std_capital_hexa_negative, .init = redirect_all_std)
{
    my_printf("hello %X", -5);
    cr_assert_stdout_eq_str("hello FFFFFFFB");
}

Test(my_printf, std_capital_octa_negative, .init = redirect_all_std)
{
    my_printf("hello %o", -5);
    cr_assert_stdout_eq_str("hello 37777777773");
}

Test(my_printf, std_num_n, .init = redirect_all_std)
{
    int *count;
    my_printf("hello %n", &count);
    my_printf("%d", count);
    cr_assert_stdout_eq_str("hello 6");
}

Test(my_printf, std_more_num_n, .init = redirect_all_std)
{
    int *count;
    my_printf("hello %c %n", '1', &count);
    my_printf("%d", count);
    cr_assert_stdout_eq_str("hello 1 8");
}

Test(my_printf, std_flag_f, .init = redirect_all_std)
{
    my_printf("hello %f", 3.4);
    cr_assert_stdout_eq_str("hello 3.400000");
}
Test(my_printf, std_flag_e_positive, .init = redirect_all_std)
{
    my_printf("hello %e", 3.0);
    cr_assert_stdout_eq_str("hello 3.000000e+00");
}

Test(my_printf, std_flag_e_negative, .init = redirect_all_std)
{
    my_printf("hello %e", 0.778);
    cr_assert_stdout_eq_str("hello 7.780000e-01");
}

Test(my_printf, std_flag_E_positive, .init = redirect_all_std)
{
    my_printf("hello %E", 3.0);
    cr_assert_stdout_eq_str("hello 3.000000E+00");
}

Test(my_printf, std_flag_E_negative, .init = redirect_all_std)
{
    my_printf("hello %E", 0.778);
    cr_assert_stdout_eq_str("hello 7.780000E-01");
}

Test(my_printf, std_flag_e_positive_neg, .init = redirect_all_std)
{
    my_printf("hello %e", -3.0);
    cr_assert_stdout_eq_str("hello -3.000000e+00");
}

Test(my_printf, std_flag_e_negative_neg, .init = redirect_all_std)
{
    my_printf("hello %e", -0.778);
    cr_assert_stdout_eq_str("hello -7.780000e-01");
}

Test(my_printf, std_flag_E_positive_neg, .init = redirect_all_std)
{
    my_printf("hello %E", -3.0);
    cr_assert_stdout_eq_str("hello -3.000000E+00");
}

Test(my_printf, std_flag_g_double_negative, .init = redirect_all_std)
{
    my_printf("%g", -5.6600);
    cr_assert_stdout_eq_str("-5.66");
}

Test(my_printf, std_flag_g_science_pos1, .init = redirect_all_std)
{
    my_printf("hello %g", 0.0000045);
    cr_assert_stdout_eq_str("hello 4.5e-06");
}

Test(my_printf, std_flag_u, .init = redirect_all_std)
{
    my_printf("hello %u", 90092);
    cr_assert_stdout_eq_str("hello 90092");
}

Test(my_printf, std_flag_u_neg_case, .init = redirect_all_std)
{
    my_printf("hello %u", -90092);
    cr_assert_stdout_eq_str("hello 4294877204");
}

Test(my_printf, std_flag_f_zero_case, .init = redirect_all_std)
{
    my_printf("hello %f", 0.00);
    cr_assert_stdout_eq_str("hello 0.000000");
}

Test(my_printf, std_flag_f_big_float_case, .init = redirect_all_std)
{
    my_printf("hello %f", 2999.9182);
    cr_assert_stdout_eq_str("hello 2999.918200");
}

Test(my_printf, std_flag_f_big_negative_float_case, .init = redirect_all_std)
{
    my_printf("hello %f", -2900.8908);
    cr_assert_stdout_eq_str("hello -2900.890800");
}

Test(my_printf, std_flag_f_big_positive_float_case, .init = redirect_all_std)
{
    my_printf("hello %f", 22900.8908);
    cr_assert_stdout_eq_str("hello 22900.890800");
}

Test(my_printf, std_flag_e_small_precision, .init = redirect_all_std)
{
    my_printf("diddy %.4e", 4.67);
    cr_assert_stdout_eq_str("diddy 4.6700e+00");
}

Test(my_printf, flag_f_precision_case, .init = redirect_all_std)
{
    my_printf("diddy %.6f", 35.67);
    cr_assert_stdout_eq_str("diddy 35.670000");
}

Test(my_printf, flag_g_positive_case, .init = redirect_all_std)
{
    my_printf("%g", 0.00002);
    cr_assert_stdout_eq_str("2e-05");
}

Test(my_printf, flag_g_neg_case, .init = redirect_all_std)
{
    my_printf("%g", -0.00002);
    cr_assert_stdout_eq_str("-2e-05");
}

Test(my_printf, std_flag_f_big_precision_case, .init = redirect_all_std)
{
    my_printf("%.10f", 123.6677);
    cr_assert_stdout_eq_str("123.6677000000");
}

Test(my_printf, std_flag_f_normal_precision_case, .init = redirect_all_std)
{
    my_printf("%.2f", 10.2129);
    cr_assert_stdout_eq_str("10.21");
}

Test(my_printf, std_flag_f_big_width_case, .init = redirect_all_std)
{
    my_printf("f = %-10f", 45.6);
    cr_assert_stdout_eq_str("f = 45.600000");
}

Test(my_printf, std_flag_f_big_width_0_case, .init = redirect_all_std)
{
    my_printf("f = %053f", 45.6);
    cr_assert_stdout_eq_str("f = 0000000000000000000000000000000000000000000045.600000");
}

Test(my_printf, std_flag_f_big_width_space_case, .init = redirect_all_std)
{
    my_printf("f = %53f", 45.6);
    cr_assert_stdout_eq_str("f =                                             45.600000");
}

Test(my_printf, f_special_width_space_case, .init = redirect_all_std)
{
    my_printf("f = %040f", 1.40);
    cr_assert_stdout_eq_str("f = 000000000000000000000000000000001.400000");
}

Test(my_printf, std_flag_f_big_negative_case, .init = redirect_all_std)
{
    my_printf("%.12f", -2000.20201);
    cr_assert_stdout_eq_str("-2000.202010000000");
}

Test(my_printf, std_flag_hashtag, .init = redirect_all_std)
{
    my_printf("%#o", 1);
    cr_assert_stdout_eq_str("01");
}

Test(my_printf, std_flag_o_hash, .init = redirect_all_std)
{
    my_printf("comp = %#o", 566);
    cr_assert_stdout_eq_str("comp = 01066");
}

Test(my_printf, std_flag_x_hash, .init = redirect_all_std)
{
    my_printf("comp = %#x", 566);
    cr_assert_stdout_eq_str("comp = 0x236");
}

Test(my_printf, std_flag_X_hash, .init = redirect_all_std)
{
    my_printf("comp = %#X", 566);
    cr_assert_stdout_eq_str("comp = 0X236");
}

Test(my_printf, std_flag_hashtag1, .init = redirect_all_std)
{
    my_printf("comp = %#o", -202);
    cr_assert_stdout_eq_str("comp = 037777777466");
}

Test(my_printf, std_flag_hashtag2, .init = redirect_all_std)
{
    my_printf("comp = %#o", 612244);
    cr_assert_stdout_eq_str("comp = 02253624");
}

Test(my_printf, std_flag_hashtag3, .init = redirect_all_std)
{
    my_printf("comp = %#e", 12.1);
    cr_assert_stdout_eq_str("comp = 1.210000e+01");
}

Test(my_printf, std_flag_hashtag4, .init = redirect_all_std)
{
    my_printf("comp = %#E", -12.1);
    cr_assert_stdout_eq_str("comp = -1.210000E+01");
}

Test(my_printf, std_flag_hashtag5, .init = redirect_all_std)
{
    my_printf("comp = %#f", 28.10);
    cr_assert_stdout_eq_str("comp = 28.100000");
}

Test(my_printf, std_flag_hashtag6, .init = redirect_all_std)
{
    my_printf("comp = %#F", 28.10);
    cr_assert_stdout_eq_str("comp = 28.100000");
}

Test(my_printf, std_flag_hashtag7, .init = redirect_all_std)
{
    my_printf("comp = %#f", -92.2);
    cr_assert_stdout_eq_str("comp = -92.200000");
}

Test(my_printf, std_flag_hashtag8, .init = redirect_all_std)
{
    my_printf("comp = %0d", 28);
    cr_assert_stdout_eq_str("comp = 28");
}

Test(my_printf, std_flag_hashtag9, .init = redirect_all_std)
{
    my_printf("comp = %0d", -28);
    cr_assert_stdout_eq_str("comp = -28");
}

Test(my_printf, std_flag_hashtag10, .init = redirect_all_std)
{
    my_printf("comp = %0i", 28);
    cr_assert_stdout_eq_str("comp = 28");
}

Test(my_printf, std_flag_hashtag11, .init = redirect_all_std)
{
    my_printf("comp = %0i", -28);
    cr_assert_stdout_eq_str("comp = -28");
}

Test(my_printf, std_flag_hashtag12, .init = redirect_all_std)
{
    my_printf("comp = %0e", 21.291);
    cr_assert_stdout_eq_str("comp = 2.129100e+01");
}

Test(my_printf, std_flag_hashtag13, .init = redirect_all_std)
{
    my_printf("comp = %0e", -21.291);
    cr_assert_stdout_eq_str("comp = -2.129100e+01");
}

Test(my_printf, std_flag_hashtag14, .init = redirect_all_std)
{
    my_printf("comp = %0e", 0.102);
    cr_assert_stdout_eq_str("comp = 1.020000e-01");
}

Test(my_printf, std_flag_hashtag15, .init = redirect_all_std)
{
    my_printf("comp = %0c", 'c');
    cr_assert_stdout_eq_str("comp = c");
}

Test(my_printf, std_flag_16, .init = redirect_all_std)
{
    my_printf("%+ x", -5);
    cr_assert_stdout_eq_str("fffffffb");
}

Test(my_printf, std_flag_17, .init = redirect_all_std)
{
    my_printf("bot = %+f", 1.0);
    cr_assert_stdout_eq_str("bot = +1.000000");
}

Test(my_printf, std_flag_18, .init = redirect_all_std)
{
    my_printf("bot = % 4d", 66);
    cr_assert_stdout_eq_str("bot =   66");
}

Test(my_printf, std_flag_19, .init = redirect_all_std)
{
    my_printf("comp = %0c", 'c');
    cr_assert_stdout_eq_str("comp = c");
}
