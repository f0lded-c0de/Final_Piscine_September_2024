/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:41:05 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/23 10:48:51 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	j = ft_strlen(dest);
	len = j;
	if (len >= size)
		return (size);
	else
		len += ft_strlen(src);
	if (size > 0)
	{
		while (src[i] && j < (size - 1))
		{
			dest[j] = src[i];
			i++;
			j++;
		}
		while (j < size)
			dest[j++] = '\0';
	}
	return (len);
}

/*void	ft_putchar(char c)
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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
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
	char	dest[13] = "Hello";

	if (argc == 3)
	{
		ft_putnbr(ft_strlcat(dest, argv[1], ft_atoi(argv[2])));
		ft_putchar('\n');
		ft_putstr(dest);
	}
	return (0);
}*/
