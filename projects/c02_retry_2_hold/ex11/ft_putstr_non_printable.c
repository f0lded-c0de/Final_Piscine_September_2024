/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:51:58 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/23 11:09:30 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthex(char c)
{
	ft_putchar('\\');
	if ((c / 16) <= 9)
		ft_putchar(c / 16 + 48);
	else
		ft_putchar(c / 16 + 87);
	if ((c % 16) <= 9)
		ft_putchar(c % 16 + 48);
	else
		ft_putchar(c % 16 + 87);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			ft_puthex(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

int	main(void)
{
	ft_putstr_non_printable("\020");
	return (0);
}
