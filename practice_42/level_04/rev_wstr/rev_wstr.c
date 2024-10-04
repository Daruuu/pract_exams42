/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_word(char *str, int start, int end)
{
	while (start < end)
	{
		write(1, &str[start], 1);
		start++;
	}
}

void	rev(char *str)
{
	int	i;
	int	len;
	int	end;
	int start;

	len = 0;
	start = -1;
	end = -1;
	while (str[len] != '\0')
		len ++;
	while (str[i] && i >= 0)
	{
		if (i == 0 && (str[i] != ' ' && str[i] != '\t'))
			start = i;
		end = i;
		if (str[i] != ' ')
		{
			while (str[i] != ' ')
				i --;
		}
		start = i + 1;
		print_word(str, start, end);
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		rev(av[1]);
	}
	return (0);
}