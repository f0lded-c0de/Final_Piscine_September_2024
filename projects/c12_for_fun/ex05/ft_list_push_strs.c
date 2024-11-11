/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:20:48 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/10 20:31:49 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*begin_list;
	t_list	*go_through;
	t_list	*new;

	if (size <= 0)
		return (NULL);
	begin_list = ft_create_elem(strs[0]);
	go_through = begin_list;
	i = 1;
	while (i < size)
	{
		new = ft_create_elem(str[i]);
		go_through->next = new;
		go_through = go_through->next;
		i++;
	}
	return (begin_list);
}
