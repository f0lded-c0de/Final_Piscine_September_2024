/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:28:55 by ale-tell          #+#    #+#             */
/*   Updated: 2024/10/07 15:00:46 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "bsq.h"

int	main(int argc, char **argv)
{
	char	*str;

	(void) argc;
	str = read_file(argv[1]);
	ft_parse_file(str);
	free(str);
	return (0);
}
