/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:46:19 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/24 15:17:54 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	while (j <= nb)
	{
		dest[i] = '\0';
		i++;
		j++;
	}
	return (dest);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
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
	char	dest[14] = "Hello";
	char	dest2[14] = "Hello";

	if (argc == 3)
	{
		ft_putstr(strncat(dest2, argv[1], ft_atoi(argv[2])));
		ft_putchar('\n');
		ft_putstr(ft_strncat(dest, argv[1], ft_atoi(argv[2])));
	}
	return (0);
}
