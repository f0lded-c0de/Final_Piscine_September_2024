/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hundreds_and_more.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:52:16 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/06 16:52:23 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_word(char *str);

void	ft_print_blocks(int rank, char **dico)
{
	int	i;
	int	j;
	int	hold;

	i = 0;
	while (dico[i])
	{
		j = 0;
		while ((dico[i][j] >= 9 && dico[i][j] <= 13) || dico[i][j] == ' ')
			j++;
		if (dico[i][j] == '1')
		{
			j++;
			hold = j;
			while (dico[i][j] == '0')
				j++;
			if ((j - hold) == rank)
				ft_print_word(dico[i]);
		}
		i++;
	}
}

void	ft_print_hundred_word(char **dico)
{
	int	i;
	int	j;
	int	hold;

	i = 0;
	while (dico[i])
	{
		j = 0;
		while ((dico[i][j] >= 9 && dico[i][j] <= 13) || dico[i][j] == ' ')
			j++;
		if (dico[i][j] == '1')
		{
			j++;
			hold = j;
			while (dico[i][j] == '0')
				j++;
			if ((j - hold) == 2)
				ft_print_word(dico[i]);
		}
		i++;
	}
}

void	ft_print_hundreds(char c, char **dico)
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
	write(1, " ", 1);
	ft_print_hundred_word(dico);
}
