#include "main.h"
#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 1204
#define SE STDERR_FILENO

/**
 * main - function to copy content to another file.
 *
 * @agc: it is the number of argument.
 * @agv: it is the arguments
 *
 * Return: 0 if it is a success,
 */
int main(int agc, char *agv[])
{
	int fd_i, fd_o, s_i, s_o;
	char buffer[1024];
	mode_t get;

	get = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	if (agc != 3)
		dprintf(SE, "Usage: cp file_from file_to\n"), exit(97);
	fd_i = open(agv[1], O_RDONLY);
	if (fd_i == -1)
		dprintf(SE, "Error: Can't read from file %s\n", agv[1]), exit(98);
	fd_o = open(agv[2], O_CREAT | O_WRONLY | O_TRUNC, get);
	if (fd_o == -1)
		dprintf(SE, "Error: Can't write to %s\n", agv[2]), exit(99);
	do {
		s_i = read(fd_i, buffer, 1024);
		if (s_i == -1)
		{
			dprintf(SE, "Error: Can't read from file %s\n", agv[1]);
			exit(98);
		}
		if (s_i > 0)
		{
			s_o = write(fd_o, buffer, (ssize_t) s_i);
			if (s_o == -1)
			{
				dprintf(SE, "Error: Can't write to %s\n", agv[2]);
				exit(99);
			}
		}
	} while (s_i > 0);
	s_i = close(fd_i);
	if (s_i == -1)
		dprintf(SE, "Error: Can't close fd %d\n", fd_i), exit(100);
	s_o = close(fd_o);
	if (s_o == -1)
		dprintf(SE, "Error: Can't close fd %d\n", fd_o), exit(100);
	return (0);
}
