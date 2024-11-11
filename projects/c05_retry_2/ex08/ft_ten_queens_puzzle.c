/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:19:17 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/05 17:32:43 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_queens(int *queens)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(queens[i] + 48);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_plcmt_ok(int *queens, int current)
{
	int	i;

	i = current - 1;
	while (i >= 0)
	{
		if ((queens[current] == queens[i])
			|| (queens[current] - queens[i]) == current - i
			|| -(queens[current] - queens[i]) == current - i)
			return (0);
		i--;
	}
	return (1);
}

void	ft_recurs_queens(int *queens, int current, int *solutions)
{
	int	i;

	i = 0;
	while (current < 10 && i < 10)
	{
		queens[current] = i;
		if (current == 0)
			ft_recurs_queens(queens, current + 1, solutions);
		else if (current < 9 && ft_plcmt_ok(queens, current))
			ft_recurs_queens(queens, current + 1, solutions);
		else if (current == 9 && ft_plcmt_ok(queens, current))
		{
			ft_print_queens(queens);
			*solutions = *solutions + 1;
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	queens[10];
	int	solutions;
	int	i;

	i = 0;
	while (i < 10)
	{
		queens[i] = 0;
		i++;
	}
	solutions = 0;
	ft_recurs_queens(queens, 0, &solutions);
	return (solutions);
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

int	main(void)
{
	ft_putnbr(ft_ten_queens_puzzle());
	return (0);
}
