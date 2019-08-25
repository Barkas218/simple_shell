#include "holberton.h"

void _error_handler(int status, int err, char **argv)
{
	_puts(program_invocation_name);
	_puts(": ");
	_printd(err);
	_puts(": ");
	_puts(argv[0]);
	_puts(": ");

	/* error msg */

	switch (status)
	{
		case 127:
			_puts("not found");
			break;
		case 2:
			_puts("Illegal number");
			break;
		default:
			break;
	}
	if (argv[1])
	{
		_puts(": ");
		_puts(argv[1]);
	}
	_puts("\n");
}
