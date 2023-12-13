#include "shell.h"

/**
 *_eputs - prints input string
 * @str: the strings to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[j]);
		j++;
	}
}

/**
 * _eputchar - write character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and error is set appropriately.
 */
int _eputchar(char c)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}

/**
 * _putsfd - write the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptors to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and error is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fd, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd - print the input string
 * @str: the strings to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int j = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
