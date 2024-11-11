/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:41:34 by ale-tell          #+#    #+#             */
/*   Updated: 2024/10/06 10:13:19 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_wordcount(char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && ft_is_inset(str[i], charset))
			i++;
		if (!str[i])
			return (j);
		while (str[i] && !ft_is_inset(str[i], charset))
			i++;
		j++;
	}
	return (j);
}

int	ft_wordlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_inset(str[i], charset))
	{
		i++;
	}
	return (i);
}

char	*ft_wrdcpy(char *str, char *charset)
{
	int		i;
	char	*word;
	int		len;

	len = ft_wordlen(str, charset);
	word = malloc(sizeof(char) *(len + 1));
	if (!word)
		return (0);
	word[len] = 0;
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**words;

	words = malloc(sizeof (char *) * (ft_wordcount(str, charset) + 1));
	if (!words)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && ft_is_inset(str[i], charset))
			i++;
		if (str[i])
		{
			words[j] = ft_wrdcpy(str + i, charset);
			if (!words[j])
				return (free_split(words));
			j++;
			i = i + ft_wordlen(str + i, charset);
		}
	}
	words[j] = 0;
	return (words);
}

void	*free_split(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}
