/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:13:00 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/21 21:07:43 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_nonimp(char *str)
{
	int	i;

	i = 0;
	while (str[i] && i < 16)
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	ft_putaddr(unsigned long long int addr, int how_far)
{
	if (addr > 15)
	{
		ft_putaddr(addr / 16, how_far + 1);
		ft_putaddr(addr % 16, 0);
	}
	else
	{
		if (how_far > 0)
			while (how_far++ < 16)
				ft_putchar('0');
		if (addr > 9)
			ft_putchar(addr + 87);
		else
			ft_putchar(addr + 48);
	}
}

int	ft_putcontent_hex(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16 && i < size && (((char *)addr)[i] != '\0'))
	{
		ft_putchar((((char *)addr)[i] / 16) + 48);
		if ((((char *)addr)[i] % 16) > 9)
			ft_putchar((((char *)addr)[i] % 16) + 87);
		else
			ft_putchar((((char *)addr)[i] % 16) + 48);
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
	if (((char *)addr)[i] == '\0' && i % 2)
		write(1, "00 ", 3);
	else if (((char *)addr)[i] == '\0')
		write(1, "00", 2);
	i++;
	return (i);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	i;
	int	j;

	ft_putaddr((unsigned long long)addr, 1);
	write(1, ": ", 2);
	i = ft_putcontent_hex(addr, size);
	j = i;
	while (i < 16)
	{
		if (i % 2)
			write(1, "   ", 3);
		else
			write(1, "  ", 2);
		i++;
	}
	ft_putstr_nonimp((char *)addr);
	ft_putchar('\n');
	if (size < 16 || ((char *)addr)[j] == '\0')
		return (addr);
	ft_print_memory(addr + 16, size - 16);
	return (addr);
}

/*int	main(void)
{
	char	str[28] = "ceci\037lmnp\177ceci\001lmnpcecilmnpi";

	ft_print_memory((void *)str, 28);
	return (0);
}*/
