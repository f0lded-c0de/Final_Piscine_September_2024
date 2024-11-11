/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:09:47 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/18 20:45:12 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_comb(char a, char b, char c, int last)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (!last)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = 0;
	while (a < 7)
	{
		b = a + 1;
		while (b <= 8)
		{
			c = b + 1;
			while (c <= 9)
			{
				ft_put_comb(a + 48, b + 48, c + 48, 0);
				c++;
			}
			b++;
		}
		a++;
	}
	ft_put_comb(a + 48, b + 47, c + 47, 1);
}
