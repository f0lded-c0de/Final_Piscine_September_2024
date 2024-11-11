/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_obstacles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:15:03 by ale-tell          #+#    #+#             */
/*   Updated: 2024/10/07 15:28:21 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_map	*find_obstacles(t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	map->ob_list = malloc(sizeof(t_ob) * map->ob_count);
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->lines[i][j] == map->ob_char)
			{
				printf("(%i, %i)\n", i,j);
				map->ob_list[k].y = j;
				map->ob_list[k].x = i;
				k++;
			}
			j++;
		}
		i++;
	}
	return (map);
}
