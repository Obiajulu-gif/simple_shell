#include "main.h"
/**
 * handle_int - entry point
 * @num: the num
 * @count: number count
 */
void handle_int(unsigned int num, size_t *count)
{
	print_integer(num, count);
}
/**
 * handle_str - entry point
 * @s: the string
 * @count: number count
 */
void handle_str(char *s, size_t *count)
{
	print_null_or_str(s, count);
}
/**
 * handle_bin - entry point
 * @num: the number
 * @count: the number count
 */
void handle_bin(unsigned int num, size_t *count)
{
	print_binary(num, count);
}

/**
 * handle_unsign - entry point
 * @num: the number
 * @count: the number count
 */
void handle_unsign(unsigned int num, size_t *count)
{
	print_unsigned(num, count);
}

/**
 * handle_octal - entry point
 * @num: the num
 * @count: the number count
 */
void handle_octal(unsigned int num, size_t *count)
{
	print_octal(num, count);
}
