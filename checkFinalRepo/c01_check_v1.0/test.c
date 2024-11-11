#include <unistd.h>
void	ft_sort_int_tab(int	*tab, int size);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr(int n)
{
	if (n < -9 || n > 9)
	{
		ft_putnbr(n / 10);
		if (n < 0)
			ft_putnbr((n % 10) * -1);
		else
			ft_putnbr(n % 10);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= -9 && n <= 9)
		ft_putchar(n + 48);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	neg;

	i = 0;
	nbr = 0;
	neg = 0;
	if (str[0] == '-')
	{
		neg = 1;
		i++;
	}
	while (str[i])
	{
		nbr *= 10;
		nbr += str[i] - 48;
		i++;
	}
	if (neg == 1)
		nbr *= -1;
	return (nbr);
}

void	ft_puttab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(tab[i++]);
		ft_putchar(' ');
	}
}

int	main(void)
{
	int	tab[9] = {9, 3, 7, 4, 6, 0, 3, 8, 1};
/*	int	i;

	i = 0;
	while (i < 9)
	{
		tab[i] = i;
		i++;
	}*/
	ft_puttab(tab, 9);
	ft_sort_int_tab(tab, 9);
	ft_putchar('\n');
	ft_puttab(tab, 9);
/*	while (i < argc)
	{
		ft_putnbr(ft_atoi(argv[i]));
		ft_putchar('\n');
		i++;
	}*/
	return (0);
}
