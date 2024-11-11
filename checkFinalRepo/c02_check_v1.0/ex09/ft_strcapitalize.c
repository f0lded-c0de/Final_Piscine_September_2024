/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:01:19 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/20 12:34:52 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

int	ft_alpha(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else if (c >= 97 && c <= 122)
		return (1);
	else if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (word == 0 && ft_alpha(str[i]) == 1)
		{
			word = 1;
			if (str[i] >= 97 && str[i] <= 122)
				str[i] -= 32;
		}
		else if (word == 1)
		{
			if (str[i] >= 65 && str[i] <= 90)
				str[i] += 32;
			if (ft_alpha(str[i]) == 0)
				word = 0;
		}
		i++;
	}
	return (str);
}

/*void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_putstr(argv[1]);
		write(1, "\n", 1);
		ft_putstr(ft_strcapitalize(argv[1]));
	}
	return (0);
}*/
