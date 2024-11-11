/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:33:13 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/09 12:09:44 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <stdlib.h>

int	ft_is_numeric(char *str)
{
	int	i;

	i = 0;
	while(str[i])
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

	tab = malloc(ac * sizeof(char *));
	if (tab == NULL)
		return (1);
	tab[ac - 1] = 0;
	i = 0;
	while (i < ac - 1)
	{
		tab[i] = av[i + 1];
		i++;
	}
	if (ft_any(tab, &ft_is_numeric))
		printf("There is at least one fully numeric argument\n");
	else
		printf("There is no fully numeric argument\n");
	free(tab);
	return (0);
}*/
