/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:33:25 by ale-tell          #+#    #+#             */
/*   Updated: 2024/10/07 18:40:41 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_sol(t_map *map, t_sol *sol)
{
	int	i;

	i = 0;
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
	sol->size = 0;
	if (sol->x == map->columns)
	{
		if (sol->y == map->rows)
			return (0);
		sol->x = 0;
		sol->y++;
	}
	else
	{
		sol->x++;
	}
	return (1);
}

int	inc_sol(t_map *map, t_sol *sol, t_sol *best)
{
	sol->size++;
	if (check_sol(map, sol) == 1)
	{
		printf("(%i, %i, %i)\n", sol->y, sol->x, sol->size);
		print_sol(map, sol);
		ft_putstr("#####################\n");
		if (inc_sol(map, sol, best) == 1)
			return (1);
	}
	else
	{
		if (sol->size > best->size)
		{

			best->x = sol->x;
			best->y = sol->y;
			best->size = sol->size - 1;
		}
		if (next_start(map, sol))
			inc_sol(map, sol, best);
		else 
			return (1);
	}
	return (0);
}

