int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				max;

	i = 0;
	max = tab[i];
	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i ++;
	}
	return (max);
}

#include <stdio.h>
int	main(void)
{
	int	tab[4] = {4, 7, 1, };
	int result = max(tab, 4);
	printf("result: %d\n", result);
	return (0);
}