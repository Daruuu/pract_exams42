#include <unistd.h>

void rotone(char *str)
{
	int	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i]<= 'y')
			str[i] = str[i] + 1;
		else if (str[i] >= 'A' && str[i]<= 'Y')
			str[i] = str[i] + 1;
		else if (str[i] == 'Z')
			str[i] = 'A';
		else if (str[i] == 'z')
			str[i] = 'a';
		write(1, &str[i], 1);
		i ++;
	}
}
int	main(int ac, char **av)
{
	if (ac == 2)
		rotone(av[1]);
	write(1, "\n", 1);
	return (0);
}

