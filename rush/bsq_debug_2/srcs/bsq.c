/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:23:25 by ale-tell          #+#    #+#             */
/*   Updated: 2024/10/08 12:10:05 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "bsq.h"


void	bsq(char *file_name)
{
	t_map	map;
	char	*str;
	t_sol	sol;
	t_sol	best;


	str = read_file(file_name);
	if (!str)
		return (ft_puterr("map error\n"));
	if (!ft_parse_file(&map ,str))
		return (ft_puterr("map error\n"));
	ft_putstr("parsing fini\n");
	init_sol(&sol);
	init_sol(&best);
	solver(&map, &sol, &best);
	if (best.size == -1)
		ft_puterr("map error\n");
	else
		print_sol(&map, &best);
	free_map(&map);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		bsq(0);
	else
	{
		i = 1;
		while (i < argc)
		{
			bsq(argv[i]);
			if ( i < argc - 1)
				ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
