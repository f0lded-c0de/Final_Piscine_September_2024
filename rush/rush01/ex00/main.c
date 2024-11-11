/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:19:56 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/28 16:12:23 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_backtrack(int grid[4][4], int val[16], int row, int col);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_checkarg(char *str)
{
	int	i;

	i = 0;
	while (i < 31)
	{
		if (i % 2 == 0)
			if (str[i] < 49 || str[i] > 52)
				return (0);
		if (i % 2 == 1)
			if (str[i] != 32)
				return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}

void	ft_print_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(grid[i][j] + 48);
			if (j < 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	val[16];
	int	grid[4][4];
	int	i;

	if (!ft_checkarg(argv[1]) || argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (i < 16)
	{
		val[i] = argv[1][i * 2] - 48;
		i++;
	}
	if (ft_backtrack(grid, val, 0, 0) == 1)
		ft_print_grid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}
