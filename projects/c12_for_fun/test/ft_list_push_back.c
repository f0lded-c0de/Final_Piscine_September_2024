/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:56:33 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/10 20:20:29 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*go_through;
	t_list	*new;

	go_through = *begin_list;
	while (go_through->next)
		go_through = go_through->next;
	new = ft_create_elem(data);
	go_through->next = new;
}
