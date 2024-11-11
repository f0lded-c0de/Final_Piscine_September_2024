/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:38:47 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/06 19:01:30 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	**ft_split(char *str);
void	ft_print_whole_number(char *str, char **dico);
void	ft_free(char **dico, int j);
void	ft_print_units(char c, char **dico);
char	**ft_assign_all(char *file_name, char *arg, char **str_ptr);

int	ft_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (i);
}

int	ft_line_is_good(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] != ':')
		return (0);
	i++;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

int	ft_dico_is_good(char **dico)
{
	int	i;

	i = 0;
	while (dico[i])
	{
		if (!ft_line_is_good(dico[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	char	**dico;
	char	*arg;

	if (ac != 2 && ac != 3)
		return (write(1, "Error\n", 6), 0);
	if (ac == 2)
		dico = ft_assign_all("numbers.dict", av[1], &arg);
	else
		dico = ft_assign_all(av[1], av[2], &arg);
	if (!ft_is_num(arg))
		return (write(1, "Error\n", 6), 0);
	if (dico == NULL || !ft_dico_is_good(dico))
		return (write(1, "Dict Error\n", 11), 0);
	i = 0;
	while (arg[i] == '0')
		i++;
	if (arg[i] == '\0')
		ft_print_units('0', dico);
	else
		ft_print_whole_number(arg, dico);
	i = 0;
	while (dico[i])
		i++;
	return (ft_free(dico, i), 0);
}
