/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:08:36 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/25 10:40:40 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_checkbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == 43 || base[i] == 45 || base[i] == 32)
			return (0);
		if (base[i] >= 9 && base[i] <= 13)
			return (0);
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_wherein_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nb;
	int	i;
	int	neg;

	if (!ft_checkbase(base))
		return (0);
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	neg = 0;
	while (str[i] == 43 || str[i] == 45)
		if (str[i++] == 45)
			neg++;
	nb = 0;
	while (ft_wherein_base(str[i], base) != -1)
	{
		nb *= ft_strlen(base);
		if (neg % 2 == 1)
			nb -= (ft_wherein_base(str[i], base));
		else
			nb += (ft_wherein_base(str[i], base));
		i++;
	}
	return (nb);
}

/*#include <unistd.h>

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
		nb *= -1;
	}
	if (nb >= -9 && nb <= 9)
		ft_putchar(nb + 48);
		
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_putnbr(ft_atoi_base(argv[1], "0123456789ABCDEF"));
	return (0);
}*/
