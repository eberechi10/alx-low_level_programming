#include"main.h"

/**
 * append_text_to_file - a function to appends text at the end file
 *
 * @filename: the name of file.
 * @text_content: the string.
 *
 * Return: If success 1, otherwise -1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int open_f, text_w;
	int count;

	count = 0;

	if (!filename)
		return (-1);


	if (text_content != NULL)

	{
		for (count = 0; text_content[count];)
			count++;
	}

	open_f = open(filename, O_WRONLY | O_APPEND);
	text_w = write(open_f, text_content, count);


	if (open_f == -1 || text_w == -1)
		return (-1);

	close(open_f);


	return (1);
}

/* appends text at the end file */
