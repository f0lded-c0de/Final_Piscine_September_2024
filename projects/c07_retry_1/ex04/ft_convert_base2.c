/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:50:33 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/02 18:51:22 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

void	ft_itoa_base(int nbr, char *base, char *dst, int size)
{
	if (size > 1)
		ft_itoa_base((nbr / ft_strlen(base)), base, dst, size - 1);
	if (nbr < 0 && size == 1)
	{
		dst[size] = base[-(nbr % ft_strlen(base))];
		dst[0] = '-';
	}
	else if (nbr < 0)
		dst[size] = base[-(nbr % ft_strlen(base))];
	else
		dst[size - 1] = base[(nbr % ft_strlen(base))];
}

char	*ft_malloc(int size, int sign)
{
	char	*dst;

	if (sign >= 0)
	{
		dst = malloc(sizeof(char) * (size + 1));
		dst[size] = '\0';
		if (dst == NULL)
			return (NULL);
	}
	else
	{
		dst = malloc(sizeof(char) * (size + 2));
		if (dst == NULL)
			return (NULL);
		dst[size + 1] = '\0';
	}
	return (dst);
}

int	main(int argc, char **argv)
{
	char	*result;

	if (argc == 4)
	{
		result = ft_convert_base(argv[1], argv[2], argv[3]);
		printf("%s\n", result);
		free(result);
		result = NULL;
	}
}
