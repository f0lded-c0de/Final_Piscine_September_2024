/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:03:53 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/09 18:15:13 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	way;

	i = 0;
	way = 0;
	while (i < (length - 1))
	{
		if (way == 0 && f(tab[i], tab[i + 1]) != 0)
			way = f(tab[i], tab[i + 1]);
		if (way < 0 && f(tab[i], tab[i + 1]) > 0)
			return (0);
		if (way > 0 && f(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

/*#include <stdio.h>
#include <stdlib.h>

int	ft_intcmp(int x, int y)
{
return (x - y);
}

int	main(int ac, char **av)
{
int	i;
int	*tab;

i = 0;
tab = malloc((ac - 1) * sizeof(int));
if (tab == NULL)
return (0);
while (i < ac - 1)
{
tab[i] = atoi(av[i + 1]);
i++;
}
if (ft_is_sort(tab, ac - 1, &ft_intcmp))
printf("The array is sorted.\n");
else
printf("The array is not sorted.\n");
free(tab);
return (0);
}*/
