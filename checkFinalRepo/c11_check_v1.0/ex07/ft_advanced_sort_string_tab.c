/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:59:30 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/09 23:09:10 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swp_str(char **s1, char **s2)
{
	char	*hold;

	hold = *s1;
	*s1 = *s2;
	*s2 = hold;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (cmp(tab[i], tab[j]) > 0)
				ft_swp_str(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}

/*#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	main(int argc, char **argv)
{
	int	i;

	(void)argc;
	ft_advanced_sort_string_tab(argv + 1, &ft_strcmp);
	i = 1;
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}*/
