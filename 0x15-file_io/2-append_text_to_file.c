#include"main.h"

/**
 * append_text_to_file -function to appends text into a file.
 *
 *@filename: it is the name of the file.
 *@text_content: the content to append into the file.
 *
 *Return: 1 on success, -1 on failure -1.
 */
int append_text_to_file(const char *filename, char *text_content)
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


	ocean = open(filename, O_APPEND | O_WRONLY);
	when = write(ocean, text_content, red);

	if (ocean == -1 || when == -1)
		return (-1);

	close(ocean);

	return (1);
}
