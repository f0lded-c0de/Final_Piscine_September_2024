/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:28:29 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/26 18:36:59 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	i = nb - 1;
	while (i >= 1)
		nb *= i--;
	return (nb);
}

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < -9 || n > 9)
	{
		ft_putnbr(n / 10);
		if (n < 0)
			ft_putnbr((n % 10) * -1);
		else
			ft_putnbr(n % 10);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= -9 && n <= 9)
		ft_putchar(n + 48);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	neg;

	i = 0;
	nbr = 0;
	neg = 0;
	if (str[0] == '-')
	{
		neg = 1;
		i++;
	}
	while (str[i])
	{
		nbr *= 10;
		nbr += str[i] - 48;
		i++;
	}
	if (neg == 1)
		nbr *= -1;
	return (nbr);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_putnbr(ft_iterative_factorial(ft_atoi(argv[1])));
	return (0);
}
