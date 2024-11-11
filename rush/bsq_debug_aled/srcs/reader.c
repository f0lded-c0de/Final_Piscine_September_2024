/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:47:53 by ale-tell          #+#    #+#             */
/*   Updated: 2024/10/08 16:34:21 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char	*loop_file(int file)
{
	int		read_size;
	int		size;
	char	*temp;
	char	*str;

	size = 0;
	read_size = READ_SIZE;
	str = malloc(1);
	if (!str)
		return (0);
	str[0] = 0;
	while (read_size == READ_SIZE)
	{
		temp = malloc(sizeof(char) * (size + READ_SIZE + 1));
		if (!temp)
			return (free(str), NULL);
		ft_strcpy(temp, str);
		free(str);
		str = temp;
		read_size = read(file, str + size, READ_SIZE);
		str[size + read_size] = 0;
		size += READ_SIZE;
	}
	return (str);
}

char	*read_file(char *file_name)
{
	int		file;
	char	*str;

	if (!file_name)
		file = 0;
	else
	{
		file = open(file_name, O_RDONLY);
		if (file == -1)
			return (0);
	}
	str = loop_file(file);
	if (file)
		close(file);
	if (!str)
		return (0);
	ft_putstr(str);
	ft_putstr("#################\n");
	return (str);
}
