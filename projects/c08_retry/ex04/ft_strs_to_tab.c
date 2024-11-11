/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:25:10 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/03 13:46:31 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(char *src)
{
	char	*dst;

	dst = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	dst = ft_strcpy(dst, src);
	return (dst);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*str_tab;
	int			i;

	str_tab = malloc((ac + 1) * sizeof(t_stock_str));
	if (str_tab == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		str_tab[i].size = ft_strlen(av[i]);
		str_tab[i].str = ft_strdup(av[i]);
		if (str_tab[i].str == NULL)
			return (NULL);
		str_tab[i].copy = ft_strdup(str_tab[i].str);
		if (str_tab[i].copy == NULL)
			return (NULL);
		i++;
	}
	str_tab[i].str = malloc(sizeof(char));
	str_tab[i].str = 0;
	return (str_tab);
}
