/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:17:05 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/02 19:29:21 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_itoa_base(int nbr, char *base, char *dst, int size);
char	*ft_malloc(int size, int sign);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_where_in_base(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_checkbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		if (base[i] == 43 || base[i] == 45)
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -sign;
		i++;
	}
	n = 0;
	while (ft_where_in_base(base, str[i]) != -1)
	{
		n = (n * ft_strlen(base)) + (ft_where_in_base(base, str[i]) * sign);
		i++;
	}
	return (n);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		midway;
	int		hold;
	int		i;
	char	*result;

	if (!ft_checkbase(base_from) || !ft_checkbase(base_to))
		return (NULL);
	midway = ft_atoi_base(nbr, base_from);
	hold = midway;
	i = 1;
	while (hold >= ft_strlen(base_to) || hold <= -ft_strlen(base_to))
	{
		hold /= ft_strlen(base_to);
		i++;
	}
	result = ft_malloc(i, midway);
	if (result == NULL)
		return (NULL);
	ft_itoa_base(midway, base_to, result, i);
	return (result);
}
