/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_whole_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:37:40 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/06 17:08:09 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_blocks(int rank, char **dico);
void	ft_print_hundreds(char c, char **dico);
void	ft_print_ten_to_twenty(char tens, char unit, char **dico);
void	ft_print_other_tens(char c, char **dico);
void	ft_print_units(char c, char **dico);

void	ft_print_word(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ' || str[i] == ':')
		i++;
	while (str[i])
	{
		while (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			i++;
		if (str[i])
			write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_still_stuff_to_print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

void	ft_print_rank(int rank, char *str, char **dico, int *block)
{
	*block = 1;
	if ((rank % 3) == 0)
		ft_print_hundreds(str[0], dico);
	else if ((rank % 3) == 2 && str[0] == '1')
	{
		ft_print_ten_to_twenty(str[0], str[1], dico);
		return ;
	}
	else if ((rank % 3) == 2)
		ft_print_other_tens(str[0], dico);
	else if ((rank % 3) == 1 && str[-1] != '1')
		ft_print_units(str[0], dico);
	if (ft_still_stuff_to_print(&str[1]) || rank > 3)
		write(1, " ", 1);
}

void	ft_print_whole_number(char *str, char **dico)
{
	int	num_len;
	int	i;
	int	rank;
	int	block;

	num_len = ft_strlen(str);
	i = 0;
	block = 0;
	while (str[i])
	{
		rank = num_len - i;
		if ((rank % 3) == 0)
			block = 0;
		if (str[i] != '0')
			ft_print_rank(rank, &str[i], dico, &block);
		if ((rank % 3) == 1 && block != 0 && rank != 1)
		{
			ft_print_blocks(rank - 1, dico);
			if (ft_still_stuff_to_print(&str[i + 1]))
				write(1, " ", 1);
		}
		i++;
	}
}
