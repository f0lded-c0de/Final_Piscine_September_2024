/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:18:52 by ale-tell          #+#    #+#             */
/*   Updated: 2024/10/09 12:50:33 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int	ft_is_mapchar(char c, t_map *map)
{
	if (c != map->em_char && c != map->ob_char)
		return (0);
	return (1);
}

int	ft_parse_first_line(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i] >= 32 && str[i] <= 126)
		i++;
	if (i < 4)
		return (-1);
	i -= 3;
	if (str[i] < 32 || str[i] > 126)
		return (-1);
	map->em_char = str[i];
	str[i] = '.';
	i++;
	if (str[i] < 32 || str[i] > 126 || str[i] == map->em_char)
		return (-1);
	map->ob_char = str[i];
	i++;
	if (str[i] < 32 || str[i] > 126
		|| str[i] == map->em_char || str[i] == map->ob_char)
		return (-1);
	map->fu_char = str[i];
	map->rows = ft_atoi(str);
	if (map->rows == 0)
		return (-1);
	return (i + 1);
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
			if (!ft_is_mapchar(map->lines[i][j], map))
				return (0);
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

int	ft_parse_file(t_map *map, char *str)
{
	int	i;

	i = ft_parse_first_line(str, map);
	if (i == -1)
	{
		free(str);
		return (0);
	}
	map->lines = ft_split(str + i, "\n");
	free(str);
	if (!map->lines)
		return (0);
	map->columns = ft_strlen(map->lines[0]);
	if (!ft_parse_map(map))
		return (free_split(map->lines), 0);
	return (1);
}
