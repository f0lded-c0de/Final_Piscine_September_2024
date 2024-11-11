/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:37:05 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/26 19:33:59 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (nb < 2147483647)
	{
		if (nb % 2 != 0)
			if (ft_is_prime(nb))
				return (nb);
		nb++;
	}
	return (0);
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
		ft_putnbr(ft_find_next_prime(ft_atoi(argv[1])));
	return (0);
}*/
