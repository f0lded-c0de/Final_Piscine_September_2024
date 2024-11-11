/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tens_and_less.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:51:39 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/06 17:03:33 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_word(char *str);

void	ft_print_ten_to_twenty(char tens, char unit, char **dico)
{
	int	i;
	int	j;

	i = 0;
	while (dico[i])
	{
		j = 0;
		while ((dico[i][j] >= 9 && dico[i][j] <= 13) || dico[i][j] == ' ')
			j++;
		if (dico[i][j] == tens && dico[i][j + 1] == unit)
			ft_print_word(dico[i]);
		i++;
	}
}

void	ft_print_other_tens(char c, char **dico)
{
	int	i;
	int	j;

	i = 0;
	while (dico[i])
	{
		j = 0;
		while ((dico[i][j] >= 9 && dico[i][j] <= 13) || dico[i][j] == ' ')
			j++;
		if (dico[i][j] == c && dico[i][j + 1] == '0'
			&& (dico[i][j + 2] == ' ' || dico[i][j + 2] == ':'))
			ft_print_word(dico[i]);
		i++;
	}
}

void	ft_print_units(char c, char **dico)
{
	int	i;
	int	j;

	i = 0;
	while (dico[i])
	{
		j = 0;
		while ((dico[i][j] >= 9 && dico[i][j] <= 13) || dico[i][j] == ' ')
			j++;
		if (dico[i][j] == c
			&& (dico[i][j + 1] == ' ' || dico[i][j + 1] == ':'))
			ft_print_word(dico[i]);
		i++;
	}
}
