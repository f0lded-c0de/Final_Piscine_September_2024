/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:18:28 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/27 13:47:02 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	size = max - min;
	if (size <= 0)
		return (0);
	*range = malloc((size + 1) * sizeof(int));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (size);
}

/*int	main(int argc, char **argv)
{
	int	*range_test;
	int	i;

	i = 0;
	if (argc == 3)
	{
		printf("%i\n\n", ft_ultimate_range(&range_test, atoi(argv[1]), atoi(argv[2])));
		if (range_test == NULL)
			printf("%s\n", (char *)range_test);
		else
		{
			while (i < (atoi(argv[2]) - atoi(argv[1])))
			{
				printf("%i\n", range_test[i]);
				i++;
			}
		}
		free(range_test);
		range_test = NULL;
	}
	return (0);
}*/
