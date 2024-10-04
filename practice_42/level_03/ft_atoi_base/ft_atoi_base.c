/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/
#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int	result;
	int	value;

	i = 0;
	sign = 1;
	result = 0;

	if (str_base < 2 || str_base > 16)
		return (0);

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i ++;

	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i ++;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			value = str[i] - '0'; 
		else if (str[i] >= 'a' && str[i] <= 'f')
			value = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			value = str[i] - 'A' + 10;
		else
			break ;
		if (value >= str_base)
			break ;
		result = result * str_base + value;
		i ++;
	}
	return (result * sign);
}

#include <stdio.h>

int	ft_atoi_base(const char *str, int base);

int	main(void)
{
	char str[] = "1a3";
	int base = 16;
	int result = ft_atoi_base(str, base);
	printf("Resultado: %d\n", result); // Debería imprimir 419
	return (0);
}

