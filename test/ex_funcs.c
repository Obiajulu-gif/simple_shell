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
