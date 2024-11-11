#include <stdio.h>
#include <stdlib.h>
#include "ft_abs.h"

int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%i", ABS(atoi(av[1])));
	return (0);
}
