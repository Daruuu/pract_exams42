/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:56:27 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/23 11:11:47 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i] != '\0' && (av[1][i] == 23 || av[1][i] == 32))
			i++;
		while (av[1][i] != 23 && av[1][i] != 32)
		{
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);

	return (0);
}
