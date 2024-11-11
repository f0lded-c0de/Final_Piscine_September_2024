/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 08:12:33 by ale-tell          #+#    #+#             */
/*   Updated: 2024/10/08 11:19:52 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_is_charset(char c, t_map *map)
{
	if (c != map->em_char && c != map->ob_char)
		return (0);
	return (1);
}

int	free_map(t_map *map)
{
	free_split(map->lines);
	free(map->ob_list);
	return (0);
}

void	init_sol(t_sol *sol)
{
	sol->y = 0;
	sol->x = 0;
	sol->size = -1;
}
