/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:20:28 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/09 12:09:31 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*map;
	int	i;

	map = malloc(sizeof(int) * length);
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		map[i] = f(tab[i]);
		i++;
	}
	return (map);
}

/*#include <stdio.h>

int	ft_is_even(int n)
{
	if (n % 2 == 0)
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	*tab;
	int	*map;

	i = 0;
	tab = malloc((ac - 1) * sizeof(int));
	if (tab == NULL)
		return (0);
	while (i < ac - 1)
	{
		tab[i] = atoi(av[i + 1]);
		i++;
	}
	map = ft_map(tab, ac - 1, &ft_is_even);
	i = 0;
	while (i < ac - 1)
	{
		if (map[i] == 0)
			printf("%i is odd !\n", tab[i]);
		else
			printf("%i is even...\n", tab[i]);
		i++;
	}
	free(tab);
	free(map);
	return (0);
}*/
