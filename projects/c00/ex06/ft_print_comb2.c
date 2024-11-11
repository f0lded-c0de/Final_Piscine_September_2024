/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:26:37 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/18 21:09:54 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_comb(int x, int y, int last)
{
	ft_putchar((x / 10) + 48);
	ft_putchar((x % 10) + 48);
	ft_putchar(' ');
	ft_putchar((y / 10) + 48);
	ft_putchar((y % 10) + 48);
	if (!last)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;

	x = 0;
	while (x < 98)
	{
		y = x + 1;
		while (y <= 99)
		{
			ft_put_comb(x, y, 0);
			y++;
		}
		x++;
	}
	ft_put_comb(x, y - 1, 1);
}
