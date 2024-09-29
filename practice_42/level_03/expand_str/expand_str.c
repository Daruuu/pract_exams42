/*
Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
$>
*/
#include <unistd.h>

void	expand_str(char *str)
{
	int	i;
	int flag;

	flag = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			flag = 1;
		}
		else
		{
			if (flag)
				write(1, "   ", 3);
			flag = 0;
			write(1, &str[i], 1);
		}
		i ++;
	}
	write(1, "\n", 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		expand_str(av[1]);
	}
	return (0);
}