/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:50:23 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/02 13:03:08 by bsamzun          ###   ########.fr       */
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

int	ft_full_len(int size, char **strs, char *sep)
{
	int	full_len;
	int	i;

	i = 0;
	full_len = (size - 1) * ft_strlen(sep);
	while (i < size)
	{
		full_len += ft_strlen(strs[i]);
		i++;
	}
	return (full_len);
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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		full_len;
	char	*result_str;

	if (size == 0)
		result_str = malloc(sizeof(char));
	else
	{
		full_len = ft_full_len(size, strs, sep);
		result_str = malloc((full_len + 1) * sizeof(char));
	}
	if (result_str == NULL)
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
	char *str;

	if (argc > 0)
	{
		str = ft_strjoin(argc - 1, argv, argv[argc - 1]);
		printf("%s\n", str);
		free(str);
	}
	return (0);
}*/
