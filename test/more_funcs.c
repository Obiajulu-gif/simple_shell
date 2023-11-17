#include "main.h"

/**
 * handle_hex - entry point
 * @num: the number
 * @is_upper: 0 if false, 1 if true
 * @count: the number count
 */
void handle_hex(unsigned int num, int is_upper, size_t *count)
{
	print_hex(num, is_upper, count);
}
