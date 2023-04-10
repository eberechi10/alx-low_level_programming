#include "main.h"

/**
 * create_file - a function that will creat a file
 *
 * @text_content: content to write into the file
 * @filename: it is the name of the file.
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int ocean, when, red;

	red = 0;

	if (!filename)
		return (-1);

	if (text_content != NULL)
	{
		for (red = 0; text_content[red];)
			red++;
	}

	ocean = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	when = write(ocean, text_content, red);

	if (ocean == -1 || when == -1)
		return (-1);

	close(ocean);

	return (1);
}
