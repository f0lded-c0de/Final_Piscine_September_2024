/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:32:06 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/10 20:42:59 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list.h"

int	main(int ac, char **av)
{
	t_list	*begin_list;
	t_list	*go_through;

	if (ac == 1)
		return (1);
	begin_list = ft_list_push_strs(ac - 1, av + 1);
	go_through = begin_list;
	while (go_through->next)
	{
		printf("%s\n", (char *)go_through->data);
		go_through = go_through->next;
	}
	return (0);
}
