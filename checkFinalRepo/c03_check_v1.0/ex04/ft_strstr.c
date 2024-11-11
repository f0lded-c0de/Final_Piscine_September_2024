/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:14:15 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/23 12:08:14 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	c_s;
	int	c_t;

	i = 0;
	while (str[i])
	{
		c_t = 0;
		c_s = i;
		while (str[c_s] == to_find[c_t] && to_find[c_t])
		{
			c_s++;
			c_t++;
		}
		if (to_find[c_t] == '\0' && c_t > 0)
			return (&str[i]);
		i++;
	}
	return (NULL);
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
	if (argc == 3)
	{
		ft_putstr(ft_strstr(argv[1], argv[2]));
		write(1, "\n", 1);
	}
	return (0);
}*/
