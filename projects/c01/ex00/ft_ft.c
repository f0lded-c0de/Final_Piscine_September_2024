/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:17:23 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/26 15:00:32 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ft(char *ptr)
{
	*ptr = 'h';
}

int	main(void)
{
	char	c;
	char	*coucou;

	c = 'g';
	write(1, &c, 1);
	coucou = &c;
	ft_ft(coucou);
	write(1, &c, 1);
}
