#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * main - generate passwords crackme5 executable.
 *
 * @argc: arguments to the program.
 * @argv: array pointer to arguments.
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char password[7], *codex;
	int lenght = strlen(argv[1]), elm, index;

	codex = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	elm = (lenght ^ 59) & 63;
	password[0] = codex[elm];

	elm = 0;
	for (index = 0; index < lenght; index++)
		elm += argv[1][index];
	password[1] = codex[(elm ^ 79) & 63];

	elm = 1;
	for (index = 0; index < lenght; index++)
		elm *= argv[1][index];
	password[2] = codex[(elm ^ 85) & 63];

	elm = 0;
	for (index = 0; index < lenght; index++)
	{
		if (argv[1][index] > elm)
			elm = argv[1][index];
	}
	srand(elm ^ 14);
	password[3] = codex[rand() & 63];

	elm = 0;
	for (index = 0; index < lenght; index++)
		elm += (argv[1][index] * argv[1][index]);
	password[4] = codex[(elm ^ 239) & 63];

	for (index = 0; index < argv[1][0]; index++)
		elm = rand();
	password[5] = codex[(elm ^ 229) & 63];

	password[6] = '\0';
	printf("%s", password);
	return (0);
}
