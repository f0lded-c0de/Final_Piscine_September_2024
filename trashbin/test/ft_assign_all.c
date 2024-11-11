/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:28:06 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/06 18:47:17 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	**ft_split(char *str);

char	**ft_extract_dico(char *file_name)
{
	int		i;
	int		size;
	int		fd;
	char	*one_line_dico;
	char	**dico;

	i = 1;
	size = 0;
	one_line_dico = malloc(0);
	while (i - 1 == size)
	{
		free(one_line_dico);
		one_line_dico = malloc(i * sizeof(char));
		if (one_line_dico == NULL)
			return (NULL);
		fd = open(file_name, O_RDONLY);
		size = read(fd, one_line_dico, i);
		close(fd);
		i++;
	}
	one_line_dico[size] = '\0';
	if (size == -1)
		return (free(one_line_dico), NULL);
	dico = ft_split(one_line_dico);
	return (free(one_line_dico), dico);
}

char	**ft_assign_all(char *file_name, char *arg, char **str_ptr)
{
	char	**dico;

	*str_ptr = arg;
	dico = ft_extract_dico(file_name);
	return (dico);
}
