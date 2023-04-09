#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - a function that reads and prints it to POSIX stdout.
 *
 * @filename: the name of the file.
 * @letters: the letters to be read and print.
 *
 * Return: if not open = 0, if filename is null = 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t ocean, red, when;
	char *buffer;

	if (!filename)
		return (0);


	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
		return (0);

	ocean = open(filename, O_RDONLY);
	red = read(ocean, buffer, letters);
	when = write(STDOUT_FILENO, buffer, red);

	if (ocean == -1 || red == -1 || when == -1 || when != red)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(ocean);

	return (when);
}
