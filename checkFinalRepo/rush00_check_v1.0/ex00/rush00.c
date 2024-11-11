/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:51:05 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/21 15:53:06 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_which_char(int x, int y, int line, int column)
{
	if ((line == 1 && column == 1) || (line == y && column == x))
		ft_putchar('o');
	else if ((line == 1 && column == x) || (line == y && column == 1))
		ft_putchar('o');
	else if (line > 1 && line < y && (column == 1 || column == x))
		ft_putchar('|');
	else if (column > 1 && column < x && (line == 1 || line == y))
		ft_putchar('-');
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
