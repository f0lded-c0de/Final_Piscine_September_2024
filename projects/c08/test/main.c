#include "ft_stock_str.h"
struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);
void	ft_show_tab(struct s_stock_str *par);

int	main(int ac, char **av)
{
	t_stock_str *stock;

	if (ac == 1)
		return (0);
	stock = ft_strs_to_tab(ac - 1, av + 1);
	stock[0].copy = "tast";
	ft_show_tab(stock);
	return (0);
}
