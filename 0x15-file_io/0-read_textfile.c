#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - a func that reads a text file and prints it to the POSIX.
 *
 * @filename: the name of the file
 * @letters: number of letters to read.
 *
 * Return: actual number of letters iit reads.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int f_des, r_text, w_text;
	char *node;


	if (!filename)
		return (0);

	f_des = open(filename, O_RDONLY);
	if (f_des == -1)
		return (0);

	node = malloc(sizeof(char) * letters);
	if (!node)
	{
		close(f_des);
		return (0);

	}
	r_text = read(f_des, node, letters);
	close(f_des);

	if (r_text == -1)
	{
		free(node);
		return (0);

	}
	w_text = write(STDOUT_FILENO, node, r_text);
	free(node);

	if (r_text != w_text)
		return (0);

	return (w_text);
}
