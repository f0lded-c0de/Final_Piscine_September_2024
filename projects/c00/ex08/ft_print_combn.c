/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:53:56 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/19 10:34:19 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_combn(int *tab, int n, int last)
{
	int	i;

	i = 0;
	while (i < n && last == 0)
		ft_putchar(tab[i++] + 48);
	while (i < n && last == 1)
	{
		tab[i] = 10 - n + i;
		ft_putchar(tab[i++] + 48);
	}
	if (!last)
		write(1, ", ", 2);
}

void	ft_recur_combn(int *tab, int n, int i)
{
	if (i == 0)
		tab[0] = 0;
	else
		tab[i] = tab[i - 1] + 1;
	while (tab[i] <= (10 - n + i))
	{
		if (i < n)
			ft_recur_combn(tab, n, i + 1);
		if (i == n - 1 && tab[0] != (10 - n))
			ft_put_combn(tab, n, 0);
		tab[i]++;
	}
	if (i == 0)
		ft_put_combn(tab, n, 1);
}

void	ft_print_combn(int n)
{
	int	tab[9];

	ft_recur_combn(tab, n, 0);
}
