/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 10:13:32 by ale-tell          #+#    #+#             */
/*   Updated: 2024/10/06 13:00:41 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	*put_error_dict_ptr(void)
{
	ft_putstr("Dict Error\n");
	return (0);
}

int	put_error_dict_int(void)
{
	ft_putstr("Dict Error\n");
	return (0);
}

void	*put_error_ptr(void)
{
	ft_putstr("Error\n");
	return (0);
}

int	put_error_int(void)
{
	ft_putstr("Error\n");
	return (0);
}
