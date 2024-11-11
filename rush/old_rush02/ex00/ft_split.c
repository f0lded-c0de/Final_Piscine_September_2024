/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:44:11 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/06 17:45:33 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_count_lines(char *str)
{
	int	i;
	int	lines;

	i = 0;
	lines = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] != '\n')
			lines++;
		i++;
	}
	return (lines);
}

int	ft_line_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char	*ft_linedup(char *str, int	*ptr)
{
	int		i;
	int		line_length;
	char	*line;

	line_length = ft_line_length(str);
	line = malloc(sizeof(char) * (line_length + 1));
	if (line == NULL)
		return (NULL);
	line[line_length] = '\0';
	i = 0;
	while (i < line_length)
	{
		line[i] = str[i];
		i++;
	}
	*ptr += i;
	return (line);
}

void	ft_free(char **dico, int j)
{
	if (j == 0)
	{
		free(dico);
		return ;
	}
	j--;
	while (j >= 0)
	{
		free(dico[j]);
		j--;
	}
	free(dico);
	return ;
}

char	**ft_split(char	*str)
{
	int		i;
	int		j;
	int		line_count;
	char	**dico;

	line_count = ft_count_lines(str);
	dico = malloc(sizeof(char *) * (line_count + 1));
	if (dico == NULL)
		return (NULL);
	dico[line_count] = 0;
	i = 0;
	j = 0;
	while (j < line_count)
	{
		while (str[i] == '\n')
			i++;
		dico[j] = ft_linedup(&str[i], &i);
		if (dico[j] == NULL)
		{
			ft_free(dico, j);
			return (NULL);
		}
		j++;
	}
	return (dico);
}
