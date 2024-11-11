/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:30:17 by bsamzun           #+#    #+#             */
/*   Updated: 2024/10/07 21:56:34 by bsamzun          ###   ########.fr       */
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
	int	wc;

	i = 0;
	wc = 0;
	if (!ft_is_sep(str[i], charset) && str[i])
		wc++;
	while (str[i])
	{
		if (ft_is_sep(str[i], charset)
			&& !ft_is_sep(str[i + 1], charset) && str[i + 1])
			wc++;
		i++;
	}
	return (wc);
}

int	ft_wordlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (!ft_is_sep(str[i], charset) && str[i])
		i++;
	return (i);
}

char	*ft_worddup(char *str, char *charset)
{
	int		i;
	int		wl;
	char	*word;

	i = 0;
	wl = ft_wordlen(str, charset);
	word = malloc(sizeof(char) * (wl + 1));
	if (word == NULL)
		return (NULL);
	word[wl] = '\0';
	while (i < wl)
	{
		word[i] = str[i];
		i++;
	}
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		wc;
	int		i;
	int		j;

	wc = ft_count_words(str, charset);
	split = malloc(sizeof(char *) * (wc + 1));
	if (split == NULL)
		return (NULL);
	split[wc] = 0;
	i = 0;
	j = 0;
	while (j < wc)
	{
		while (ft_is_sep(str[i], charset))
			i++;
		split[j] = ft_worddup(&str[i], charset);
		if (split[j] == NULL)
			return (NULL);
		while (!ft_is_sep(str[i], charset) && str[i])
			i++;
		j++;
	}
	return (split);
}

/*#include <stdio.h>

int	main(int ac, char **av)
{
	char	**split;
	int		i;

	if (ac != 3)
		return (0);
	split = ft_split(av[1], av[2]);
	if (split == NULL)
		return (0);
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
	return (0);
}*/
