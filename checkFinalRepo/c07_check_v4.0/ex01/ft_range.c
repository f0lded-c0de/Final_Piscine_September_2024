/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:51:48 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/01 18:51:00 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if ((max - min) <= 0)
		return (NULL);
	tab = malloc((max - min) * sizeof(int));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (min < max)
		tab[i++] = min++;
	return (tab);
}

/*int	main(int argc, char **argv)
{
	int	*tesb;
	int	i;

	i = 0;
	if (argc == 3)
	{
		tesb = ft_range(atoi(argv[1]), atoi(argv[2]));
		if (tesb == NULL)
			printf("%s\n", (char *)tesb);
		else
		{
			while (i < (atoi(argv[2]) - atoi(argv[1])))
			{
				printf("%i\n", tesb[i]);
				i++;
			}
		}
		free(tesb);
		tesb = NULL;
	}
	return (0);
}*/
