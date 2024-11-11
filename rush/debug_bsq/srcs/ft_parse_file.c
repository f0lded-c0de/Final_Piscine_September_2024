/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:18:52 by ale-tell          #+#    #+#             */
/*   Updated: 2024/10/07 17:22:05 by ale-tell         ###   ########.fr       */
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

int	ft_is_charset(char c, t_map *map)
{
	if (c != map->em_char && c != map->ob_char)
		return (0);
	return (1);
}

int	ft_parse_map(t_map *map)
{
	int	i;
	int	j;
	int	ob_count;

	i = 0;
	ob_count = 0;
	map->columns = ft_strlen(map->lines[0]);
	while (map->lines[i])
	{
		j = 0;
		while (map->lines[i][j])
		{
			if (!ft_is_charset(map->lines[i][j], map))
				return (0);
			if (map->lines[i][j] == map->ob_char)
				ob_count++;
			j++;
		}
		if (j != map->columns)
			return (0);
		i++;
	}
	if (i != map->rows)
		return (0);
	return (map->ob_count = ob_count, 1);
}

int	ft_parse_file(t_map *map, char *str)
{
	int	i;

	i = ft_parse_first_line(str, map);
	if (i == -1)
		return (0);
	map->lines = ft_split(str + i, "\n");
	if (map->lines == NULL)
		return (0);
	if (!ft_parse_map(map))
		return (0);
	return (1);
}

/*	printf("Nombre de lignes : %i\n", map->rows);
	printf("Nombre de colonnes : %i\n", map->columns);
	printf("Char vide : %c\n", map->em_char);
	printf("Char obstacle : %c\n", map->ob_char);
	printf("Char plein : %c\n", map->fu_char);
	printf("Nombre d'obstacles : %i\n", map->ob_count);*/
