/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:32:34 by bsamzun           #+#    #+#             */
/*   Updated: 2024/09/21 16:54:40 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

/*void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	ft_putchar(ft_str_is_printable(" 2898r71235y@@@YT@^*&()^$ fsgee ") + 48);
	ft_putchar('\n');
	ft_putchar(ft_str_is_printable("\x7f fsfwahaeha35yhe\x7f") + 48);
	ft_putchar('\n');
	ft_putchar(ft_str_is_printable("\x1f ajdfnlawkneg; \x1f") + 48);
	ft_putchar('\n');
	return (0);
}*/
