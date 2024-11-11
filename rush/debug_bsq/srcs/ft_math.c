/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:26:59 by ale-tell          #+#    #+#             */
/*   Updated: 2024/10/07 18:23:16 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_max(int x, int y)
{
	if (x - y)
		return (x);
	return (y);
}

int	ft_min(int x, int y)
{
	if (x - y)
		return (y);
	return (x);
}

int isin_inter(int i, int min, int max)
{
	if (min <= i && i <= max)
		return (1);
	return (0);
}

int isin_inter_strict(int i, int min, int max)
{
	if (min < i && i < max)
		return (1);
	return (0);
}
