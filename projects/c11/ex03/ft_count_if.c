/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:53:54 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/09 13:18:38 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}

/*#include <stdio.h>
#include <stdlib.h>

int	ft_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	**tab;
	int		i;

	tab = malloc((ac - 1) * sizeof(char *));
	if (tab == NULL)
		return (1);
	i = 0;
	while (i < ac - 1)
	{
		tab[i] = av[i + 1];
		i++;
	}
	printf("There is %i", ft_count_if(tab, ac - 1, &ft_is_numeric));
	printf(" fully numeric arguments\n");
	free(tab);
	return (0);
}*/
