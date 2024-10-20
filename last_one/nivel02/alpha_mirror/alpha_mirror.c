/*
Assignment name  : alpha_mirror
		Expected files   : alpha_mirror.c
		Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
		after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
		$>./alpha_mirror "My horse is Amazing." | cat -e
		Nb slihv rh Znzarmt.$
		$>./alpha_mirror | cat -e
		$
$>*/
#include <unistd.h>

void	alpha_mirror(char *str)
{
	int	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = ('z' + 'a') - str[i] ;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = ('Z' + 'A') - str[i] ;
		write(1, &str[i], 1);
		i ++;
	}
}
#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2)
		alpha_mirror(av[1]);
	write(1, "\n", 1);
	return (0);
}