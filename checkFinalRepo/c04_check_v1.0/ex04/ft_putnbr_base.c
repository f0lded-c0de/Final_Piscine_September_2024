/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:52:04 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/25 10:45:37 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_checkbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == 43 || base[i] == 45)
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

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_checkbase(base))
	{
		if (nbr >= ft_strlen(base) || nbr <= -ft_strlen(base))
		{
			ft_putnbr_base(nbr / ft_strlen(base), base);
			if (nbr < 0)
				ft_putnbr_base((nbr % ft_strlen(base)) * -1, base);
			else
				ft_putnbr_base(nbr % ft_strlen(base), base);
		}
		else if (nbr < 0)
		{
			ft_putchar('-');
			ft_putchar(base[-nbr]);
		}
		else
			ft_putchar(base[nbr]);
	}
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
	if (argc == 3)
		ft_putnbr_base(ft_atoi(argv[1]), argv[2]);
	return (0);
}*/
