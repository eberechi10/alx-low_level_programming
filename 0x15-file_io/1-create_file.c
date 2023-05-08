#include "main.h"

/**
 * create_file - a function to create a file.
 *
 * @filename: the name of the file.
 * @text_content: the string.
 *
 * Return: If success 1, otherwise - 1.
 */

int create_file(const char *filename, char *text_content)
{
	int open_f, text_w;
	int count;

	count = 0;

	if (!filename)
		return (-1);

/* creat a file */

	if (text_content != NULL)
	{
		for (count = 0; text_content[count];)
			count++;
	}

	open_f = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	text_w = write(open_f, text_content, count);

	if (open_f == -1 || text_w == -1)
		return (-1);

	close(open_f);


	return (1);
}
