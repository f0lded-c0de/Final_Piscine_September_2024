/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:00:37 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/21 15:10:37 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_put_corner(int x, int y, int line, int column)
{
	if (y != 1 && x != 1)
	{
		if ((line == 1 && column == 1) || (line == y && column == 1))
			ft_putchar('A');
		else if ((line == 1 && column == x) || (line == y && column == x))
			ft_putchar('C');
	}
	else if (y == 1)
	{
		if (column == 1)
			ft_putchar('A');
		else if (column == x)
			ft_putchar('C');
	}
	else if (x == 1)
		ft_putchar('A');
}

void	ft_which_char(int x, int y, int line, int column)
{
	if ((line == 1 && column == 1) || (line == y && column == x))
		ft_put_corner(x, y, line, column);
	else if ((line == 1 && column == x) || (line == y && column == 1))
		ft_put_corner(x, y, line, column);
	else if (line > 1 && line < y && (column == 1 || column == x))
		ft_putchar('B');
	else if (column > 1 && column < x && (line == 1 || line == y))
		ft_putchar('B');
	else if (line > 1 && line < y && column > 1 && column < x)
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	line;
	int	column;

	line = 1;
	if (x > 0 && y > 0)
	{
		while (line <= y)
		{
			column = 1;
			while (column <= x)
			{
				ft_which_char(x, y, line, column);
				column++;
			}
			ft_putchar('\n');
			line++;
		}
	}
}
