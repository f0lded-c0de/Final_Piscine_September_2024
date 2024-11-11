/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:03:12 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/04 11:10:18 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	if (str[i] && !ft_is_sep(str[i], charset))
		count = 1;
	else
		count = 0;
	while (str[i])
	{
		if (ft_is_sep(str[i], charset)
			&& (!ft_is_sep(str[i + 1], charset) && str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

int	cs_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (!ft_is_sep(str[i], charset) && str[i])
		i++;
	return (i);
}

char	*cs_strcpy(char *src, char *charset)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc(sizeof(char) * (cs_strlen(src, charset) + 1));
	if (dst == NULL)
		return (NULL);
	while (!ft_is_sep(src[i], charset) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		word_count;
	int		i;
	int		j;

	word_count = ft_count_words(str, charset);
	split = malloc((word_count + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	split[word_count] = 0;
	i = 0;
	j = 0;
	while (j < word_count && str[i])
	{
		while (ft_is_sep(str[i], charset))
			i++;
		if (str[i])
			split[j] = cs_strcpy(&str[i], charset);
		while (!ft_is_sep(str[i], charset) && str[i])
			i++;
		j++;
	}
	return (split);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	char	**split;

	if (argc == 3)
	{
		printf("Nombre de mots : %i\n\n", ft_count_words(argv[1], argv[2]));
		split = ft_split(argv[1], argv[2]);
		i = 0;
		while (split[i])
		{
			printf("%s\n", split[i]);
			i++;
		}
		i = 0;
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
	return (0);
}
