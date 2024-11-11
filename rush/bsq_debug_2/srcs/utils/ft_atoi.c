/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:44:51 by ale-tell          #+#    #+#             */
/*   Updated: 2024/10/07 11:30:19 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_basetodec(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	ret;
	int	i;
	int	sign;
	int	base_size;

	ret = 0;
	i = 0;
	sign = 1;
	base_size = ft_is_base_valid(base);
	if (base_size < 2)
		return (0);
	while (ft_is_whitespace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_basetodec(str[i], base) != -1)
	{
		ret = ret * base_size + (ft_basetodec(str[i], base));
		i++;
	}
	return (sign * ret);
}

int	ft_atoi(char *str)
{
	return (ft_atoi_base(str, "0123456789"));
}
