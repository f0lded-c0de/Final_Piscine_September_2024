/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:23:25 by ale-tell          #+#    #+#             */
/*   Updated: 2024/10/07 18:40:14 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "bsq.h"

void free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return;
	if (map->lines)
		free_split(map->lines);
	if (map->ob_list)
		free(map->ob_list);
}

int	main(int argc, char **argv)
{
	t_map	map;
	char	*str;
	t_sol	sol;
	t_sol	best;

	sol.y = 0;
	sol.x = 0;
	sol.size = -1;
	
	best.y = 0;
	best.x = 0;
	best.size = -1;
	if (argc != 2)
		return (1);
	
	str = read_file(argv[1]);
	ft_parse_file(&map ,str);
	free(str);
	find_obstacles(&map);
	
	inc_sol(&map, &sol, &best);

	
	printf("Best sol : (%i, %i, %i)\n", best.y, best.x, best.size);
	print_sol(&map, &best);

	free_map(&map);
	return (0);
}
