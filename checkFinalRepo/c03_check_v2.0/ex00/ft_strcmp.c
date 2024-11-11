/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 09:13:18 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/22 09:26:29 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if ((s1[i] - s2[i]) != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

/*void	ft_putchar(char c)
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

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_putnbr(ft_strcmp(argv[1], argv[2]));
		ft_putchar('\n');
	}
	return (0);
}*/
