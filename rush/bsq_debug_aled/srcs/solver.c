/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:33:25 by ale-tell          #+#    #+#             */
/*   Updated: 2024/10/08 16:34:59 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_sol(t_map *map, t_sol *sol, t_sol *best)
{
	int	i;

	if (sol->x >= map->columns - best->size || sol->y >= map->rows - best->size)
		return (0);
	if (sol->x + sol->size >= map->columns || sol->y + sol->size >= map->rows)
		return (0);
	i = sol->x;
	while (i < sol->x + sol->size)
	{
		if (map->lines[sol->y + sol->size][i] == map->ob_char)
			return (0);
		i++;
	}
	i = sol->y;
	while (i < sol->y + sol->size)
	{
		if (map->lines[i][sol->x + sol->size] == map->ob_char)
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
	while (next_start(map, sol))
	{
		while (check_sol(map, sol, best) == 1)
			sol->size++;
		if (sol->size - 1 > best->size)
		{
			best->x = sol->x;
			best->y = sol->y;
			best->size = sol->size - 1;
		}
	}	
}
