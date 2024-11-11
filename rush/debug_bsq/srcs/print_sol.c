/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:18:31 by ale-tell          #+#    #+#             */
/*   Updated: 2024/10/07 18:35:52 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	putline(int index, t_map *map, t_sol *sol)
{
	int	i;
	int	size;
	char *line;

	line = map->lines[index];
	size = sol->size;
	i = 0;
	while (line[i])
	{
		if (isin_inter(i, sol->x, sol->x + size)
			&& isin_inter(index, sol->y, sol->y + size))
				//printf("%c",map->fu_char );
				ft_putchar(map->fu_char);
		else
			//printf("%c",line[i] );
			ft_putchar(line[i]);
		i++;
	}
}

void	print_sol(t_map *map, t_sol *sol)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		putline(i, map, sol);
	//	ft_putchar('\n');
		printf("\n");
		i++;
	}
}
