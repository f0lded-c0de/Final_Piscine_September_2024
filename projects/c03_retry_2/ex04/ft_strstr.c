/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:14:15 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/24 18:45:32 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	c_s;
	int	c_t;

	i = 0;
	if (!to_find[i])
		return (str);
	while (str[i])
	{
		c_t = 0;
		c_s = i;
		while (str[c_s] == to_find[c_t] && to_find[c_t])
		{
			c_s++;
			c_t++;
		}
		if (to_find[c_t] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}

/*int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%s\n", strstr(argv[1], argv[2]));
		printf("%s\n", ft_strstr(argv[1], argv[2]));
	}
	return (0);
}*/
