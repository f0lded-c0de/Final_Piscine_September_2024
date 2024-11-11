/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:50:23 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/01 18:53:16 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dst, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	int	tot_size;
	char *result_str;

	i = 0;
	tot_size = (size - 1) * ft_strlen(sep);
	while (i < size)
	{
		tot_size += ft_strlen(strs[i]);
		i++;
	}
	result_str = malloc((tot_size + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result_str[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(result_str, strs[i]);
		if (i < size - 1)
			ft_strcat(result_str, sep);
		i++;
	}
	return (result_str);
}

/*int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 5)
		printf("%s\n", ft_strjoin(4, argv, argv[4]));
	return (0);
}*/
