#ifndef MAIN_H_
#define MAIN_H_

#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>


/* The header file */

int _strlen(char *str);
int append_text_to_file(const char *filename, char *text_content);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int _putchar(char c);

/* The File i/o */

#endif
