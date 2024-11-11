/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:33:25 by ale-tell          #+#    #+#             */
/*   Updated: 2024/10/08 12:21:22 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	fill(t_map *map, t_sol *sol)
{
	int	i;
	int	j;

	i = sol->y;
	while (i < (sol->y + sol->size))
	{
		j = sol->x;
		while (j < (sol->x + sol->size))
		{
			map->lines[i][j] = -1;
			j++;
		}
		i++;
	}
}

int	check_sol(t_map *map, t_sol *sol)
{
	int	i;

	i = 0;
	if (map->lines[sol->y][sol->x] == -1)
		return (0);
	if (sol->x + sol->size >= map->columns || sol->y + sol->size >= map->rows)
		return (0);
	while (i < map->ob_count)
	{
		if (map->ob_list[i].x == sol->x + sol->size
				&& isin_inter(map->ob_list[i].y, sol->y, sol->y + sol->size))
			return (0);
		if (map->ob_list[i].y == sol->y + sol->size
				&& isin_inter(map->ob_list[i].x, sol->x, sol->x + sol->size))
			return (0);
		i++;
	}
	return (1);
}

int	next_start(t_map *map, t_sol *sol)
{
	sol->size = -1;
	if (sol->x == map->columns - 1)
	{
		if (sol->y == map->rows - 1)
			return (0);
		sol->x = 0;
		sol->y++;
	}
	else
		sol->x++;
	return (1);
}

void	solver(t_map *map, t_sol *sol, t_sol *best)
{
	sol->size++;
	if (check_sol(map, sol) == 1)
		solver(map, sol, best);
	else
	{
		if (sol->size - 1 > best->size)
		{
			best->x = sol->x;
			best->y = sol->y;
			best->size = sol->size - 1;
		}
		fill(map, sol);
		if (next_start(map, sol))
			solver(map, sol, best);
	}
}
