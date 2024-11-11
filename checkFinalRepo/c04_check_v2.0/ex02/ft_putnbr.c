/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:59:08 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/24 09:20:30 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < -9 || nb > 9)
	{
		ft_putnbr(nb / 10);
		if (nb < 0)
			ft_putnbr((nb % 10) * -1);
		else
			ft_putnbr(nb % 10);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putchar(-nb + 48);
	}
	else
		ft_putchar(nb + 48);
}

/*int	ft_atoi(char *str)
{
	int	nb;
	int	i;
	int	neg;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	neg = 0;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			neg++;
		i++;
	}
	nb = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb *= 10;
		if (neg % 2 == 1)
			nb -= (str[i] - 48);
		else
			nb += str[i] - 48;
		i++;
	}
	return (nb);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_putnbr(ft_atoi(argv[1]));
	return (0);
}*/
