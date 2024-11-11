/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:35:32 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/09 22:11:08 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "op.h"

int	ft_opi(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -sign;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = (nb * 10) + ((str[i] - 48) * sign);
		i++;
	}
	return (nb);
}

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
		nb = -nb;
		ft_putchar(nb + 48);
	}
	else
		ft_putchar(nb + 48);
}

int	main(int ac, char **av)
{
	int	(*p[5])(int, int);

	p[0] = ft_add;
	p[1] = ft_sub;
	p[2] = ft_div;
	p[3] = ft_mul;
	p[4] = ft_mod;
	if (ac != 4)
		return (1);
	else if ((ft_opi(av[2][0], "+-/*%") == 2
		|| ft_opi(av[2][0], "+-/*%") == 4)
		&& ft_atoi(av[3]) == 0)
		write(1, "Stop : division by zero\n", 25);
	else if (ft_opi(av[2][0], "+-/*%") != -1 && av[2][1] == '\0')
	{
		ft_putnbr(p[ft_opi(av[2][0], "+-/*%")](ft_atoi(av[1]), ft_atoi(av[3])));
		write(1, "\n", 1);
	}
	else
	{
		ft_putnbr(0);
		write(1, "\n", 1);
	}
	return (0);
}
