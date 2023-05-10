#include <unistd.h>
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void print_osabi(const Elf64_Ehdr *head_elf);
void print_type(const Elf64_Ehdr *head_elf);
void print_entry(const Elf64_Ehdr *head_elf);
void elf_display(const Elf64_Ehdr *head_elf);
void elf_error(const char *mesg_err);
void print_version(const Elf64_Ehdr *head_elf);


/**
 * elf_display - a function to display elf.
 *
 * @head_elf: a point to elf class
 *
 * Return: void
 */
void elf_display(const Elf64_Ehdr *head_elf)
{
	int sun;

	printf("ELF Header:\n");

	printf("  Magic:   ");

	for (sun = 0; sun < (EI_NIDENT - 1); sun++)
		printf("%02x ", head_elf->e_ident[sun]);
	printf("%02x", head_elf->e_ident[sun]);
	printf("\n");

	printf("  Class:                             %s\n",
			head_elf->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");

	printf("  Data:                              %s\n",
			head_elf->e_ident[EI_DATA] == ELFDATA2LSB
			? "2's complement, little endian"
			: "2's complement, big endian");

	print_version(head_elf);
	print_osabi(head_elf);

	printf("  ABI Version:                       %d\n",
			head_elf->e_ident[EI_ABIVERSION]);

	print_type(head_elf);

	print_entry(head_elf);
}

/**
 * elf_error - a function to print ELF error message.
 *
 * @mesg_err: a pointer holding ELF class
 *
 * Return: error message
 */
void elf_error(const char *mesg_err)
{
	fprintf(stderr, "Error: %s\n", mesg_err);
	exit(98);
}

/**
 * print_entry - a function to print ELF header entry point.
 *
 * @head_elf: a pointer holding the ELF class.
 */

void print_entry(const Elf64_Ehdr *head_elf)
{
	const unsigned char *get;
	Elf64_Addr sen;

	get = head_elf->e_ident;
	sen = head_elf->e_entry;

	printf("  Entry point address:               ");


	if (get[EI_DATA] == ELFDATA2MSB)
	{
		sen = ((sen << 8) & 0xFF00FF00) |
			  ((sen >> 8) & 0xFF00FF);
		sen = (sen << 16) | (sen >> 16);
	}


	if (get[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)sen);

	else
		printf("%#lx\n", sen);
}

/**
 * print_version - Prints the version of an ELF header.
 *
 * @head_elf: a pointer to ELF version
 */

void print_version(const Elf64_Ehdr *head_elf)
{
	printf("  Version:                           %d",
			head_elf->e_ident[EI_VERSION]);


	if (head_elf->e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * main - a function to check ELF code.
 *
 * @argc: arguments used
 * @argv: a the argument pointer
 *
 * Return: Always 0.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	const char *path_p;
	int f_des;
	Elf64_Ehdr head_elf;

	if (argc != 2)
		elf_error("Usage: elf_header elf_filename");

	path_p = argv[1];

	f_des = open(path_p, O_RDONLY);
	if (f_des < 0)
		elf_error("Failed to open file");


	if (read(f_des, &head_elf, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		close(f_des);
		elf_error("Failed to read ELF header");
	}


	if (head_elf.e_ident[EI_MAG0] != ELFMAG0 ||
		head_elf.e_ident[EI_MAG1] != ELFMAG1 ||
		head_elf.e_ident[EI_MAG2] != ELFMAG2 ||
		head_elf.e_ident[EI_MAG3] != ELFMAG3)
	{
		elf_error("The file is not an ELF file");
	}

	elf_display(&head_elf);

	close(f_des);

	return (0);
}

/**
 * print_osabi - a function to print ELF header osabi.
 *
 * @head_elf: a pointer to ELF version
 */

void print_osabi(const Elf64_Ehdr *head_elf)
{
	printf("  OS/ABI:                            ");
	switch (head_elf->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM_AEABI:
			printf("ARM EABI\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", head_elf->e_ident[EI_OSABI]);
			break;
	}
}

/**
 * print_type - a function to print ELF header type.
 *
 * @head_elf: a pointer holding the ELF class
 */

void print_type(const Elf64_Ehdr *head_elf)
{
	unsigned int e_type = head_elf->e_type;

	if (head_elf->e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
			break;
	}
}
