/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:18:52 by ale-tell          #+#    #+#             */
/*   Updated: 2024/10/08 11:18:29 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int	ft_parse_first_line(char *str, t_map *map)
{
	int	i;

	map->rows = ft_atoi(str);
	if (map->rows == 0)
		return (-1);
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\n' || str[i] == '\0' || str[i] < 32 || str[i] > 126)
		return (-1);
	map->em_char = str[i];
	i++;
	if (str[i] == '\n' || str[i] == '\0' || str[i] < 32 || str[i] > 126
		|| str[i] == map->em_char)
		return (-1);
	map->ob_char = str[i];
	i++;
	if (str[i] == '\n' || str[i] == '\0' || str[i] < 32 || str[i] > 126
		|| str[i] == map->em_char || str[i] == map->ob_char)
		return (-1);
	map->fu_char = str[i];
	i++;
	return (i);
}

int	ft_parse_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->lines[i])
	{
		j = 0;
		while (map->lines[i][j])
		{
			if (!ft_is_charset(map->lines[i][j], map))
				return (0);
			if (map->lines[i][j] == map->ob_char)
				map->ob_count++;
			j++;
		}
		if (j != map->columns)
			return (0);
		i++;
	}
	if (i != map->rows)
		return (0);
	return (1);
}

t_map	*find_obstacles(t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	map->ob_list = malloc(sizeof(t_ob) * map->ob_count);
	if (!map->ob_list)
		return (0);
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->lines[i][j] == map->ob_char)
			{
				map->ob_list[k].y = i;
				map->ob_list[k].x = j;
				k++;
			}
			j++;
		}
		i++;
	}
	return (map);
}

int	ft_parse_file(t_map *map, char *str)
{
	int	i;

	i = ft_parse_first_line(str, map);
	if (i == -1)
	{
		free(str);
		return (0);
	}
	map->ob_count = 0;
	map->lines = ft_split(str + i, "\n");
	free(str);
	if (!map->lines)
		return (0);
	map->columns = ft_strlen(map->lines[0]);
	if (!ft_parse_map(map))
		return (free_split(map->lines), 0);	
	if (!find_obstacles(map))
		return (free_split(map->lines), 0);	
		
	return (1);
}


