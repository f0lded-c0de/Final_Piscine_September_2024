/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:00:51 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/28 15:57:33 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	test_lign(int tab[4][4], int val, int row, int col);
int	test_lign_rev(int tab[4], int val);
int	test_col(int tab[4][4], int val, int row, int col);
int	test_col_rev(int tab[4][4], int val, int nb_col);

int	ft_already_in_row(int grid[4][4], int row, int col)
{
	int	i;

	i = col - 1;
	while (i >= 0)
	{
		if (grid[row][col] == grid[row][i])
			return (0);
		i--;
	}
	return (1);
}

int	ft_already_in_col(int grid[4][4], int row, int col)
{
	int	i;

	i = row - 1;
	while (i >= 0)
	{
		if (grid[row][col] == grid[i][col])
			return (0);
		i--;
	}
	return (1);
}

int	ft_checkall(int grid[4][4], int val[16], int row, int col)
{
	if (!ft_already_in_row(grid, row, col))
		return (0);
	if (!ft_already_in_col(grid, row, col))
		return (0);
	if (!test_lign(grid, val[row + 8], row, col))
		return (0);
	if (!test_col(grid, val[col], row, col))
		return (0);
	if (col == 3 && !test_lign_rev(grid[row], val[row + 12]))
		return (0);
	if (row == 3 && !test_col_rev(grid, val[col + 4], col))
		return (0);
	return (1);
}

int	ft_backtrack(int grid[4][4], int val[16], int row, int col)
{
	int	v;
	int	finished;

	v = 1;
	finished = 0;
	while (v <= 4)
	{
		grid[row][col] = v;
		if (ft_checkall(grid, val, row, col))
		{
			if (col != 3)
				finished = ft_backtrack(grid, val, row, col + 1);
			else if (col == 3 && row != 3)
			{	
				finished = ft_backtrack(grid, val, row + 1, 0);
			}
			else if (col == 3 && row == 3)
				return (1);
			if (finished == 1)
				return (1);
		}
		v++;
	}
	return (finished);
}
