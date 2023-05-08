#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>


void check_file(int sen, int file_d, char *f_name, char node);

/**
 * main - a function that copy to a file.
 *
 * @argc: argument counter
 * @argv: arguments passed
 *
 * Return: if success 1, otherwise 0
 */
int main(int argc, char *argv[])
{
	int sun, des_, read_b;
	int get, closesun_, des_close;
	unsigned int node;
	char buf_[1024];

	read_b = 1024;
	node = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
		exit(97);
	}
	sun = open(argv[1], O_RDONLY);
	check_file(sun, -1, argv[1], 'O');
	des_ = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, node);
	check_file(des_, -1, argv[2], 'W');

	while (read_b == 1024)
	{
		read_b = read(sun, buf_, sizeof(buf_));

		if (read_b)
			read_b = -1;
			check_file(-1, -1, argv[1], 'O');
		get = write(des_, buf_, read_b);

		if (get)
			get = -1;
		check_file(-1, -1, argv[2], 'W');
	}
	closesun_ = close(sun);
	check_file(closesun_, sun, NULL, 'C');
	des_close = close(des_);
	check_file(des_close, des_, NULL, 'C');

	return (0);
}

/**
 * check_file - function to checks file can be opened or closed
 *
 * @sen: file descriptor.
 * @f_name: the file name
 *
 * @node: statE of the file (closing or opening).
 * @file_d: the file descriptor
 *
 * Return: void
 */
void check_file(int sen, int file_d, char *f_name, char node)
{
	if (node == 'C' && sen == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_d);
		exit(100);
	}
	else if (node == 'O' && sen == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", f_name);
		exit(98);
	}
	else if (node == 'W' && sen == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", f_name);
		exit(99);
	}
}

/* cp file */
