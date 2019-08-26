#include "holberton.h"

void _error_handler(int status, int err, char **argv)
{
	/* error msg */

	switch (status)
	{
		case 127:
			_print_base_error(err, argv);
			_puts("not found");
			_puts("\n");
			break;
		case 2:
			_print_base_error(err, argv);
			_puts("Illegal number");
			if (argv[1])
			{
				_puts(": ");
				_puts(argv[1]);
				_puts("\n");
			}
			break;
		default:
			break;
	}
}

void _print_base_error(int err, char **argv)
{
	_puts(program_invocation_name);
	_puts(": ");
	_printd(err);
	_puts(": ");
	_puts(argv[0]);
	_puts(": ");
}
