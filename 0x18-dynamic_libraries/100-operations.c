#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);


/**
 * add - function to sums two numbers.
 *
 * @a: First number.
 * @b: Second number.
 *
 * Return: sum of the operation.
 */
int add(int a, int b)
{
	return (a + b);
}


/**
 * sub - function to sub number from a number.
 *
 * @a: First number.
 * @b: Second number.
 *
 * Return: the sub operation.
 */
int sub(int a, int b)
{
	return (a - b);
}


/**
 * mul - a function ton multipy two integer.
 *
 * @a: First number.
 * @b: Second number.
 *
 * Return: result of operation.
 */
int mul(int a, int b)
{
	return (a * b);
}


/**
 * div - a function to divide a number by another number.
 *
 * @a: First number.
 * @b: Second number.
 *
 * Return: result of the operation.
 */
int div(int a, int b)
{
	return (a / b);
}


/**
 * mod - remainder when a number is divided by another.
 *
 * @a: First number.
 * @b: Second number.
 *
 * Return: Integer result of operation.
 */

int mod(int a, int b)
{
	return (a % b);
}
