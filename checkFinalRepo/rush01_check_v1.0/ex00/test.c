/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmanique <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:57:51 by gmanique          #+#    #+#             */
/*   Updated: 2024/09/28 15:56:13 by gmanique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	test_lign(int tab[4][4], int val, int row, int col)
{
	int	i;
	int	taille;
	int	cpt;	

	i = 0;
	taille = 0;
	cpt = 0;
	while (i <= col)
	{
		if (tab[row][i] > taille)
		{
			cpt ++;
			taille = tab[row][i];
		}
		i++;
	}
	return (cpt <= val && cpt >= val - (3 - col));
}

int	test_lign_rev(int tab[4], int val)
{
	int	i;
	int	taille;
	int	cpt;

	i = 3;
	taille = 0;
	cpt = 0;
	while (i >= 0)
	{
		if (tab[i] > taille)
		{
			cpt ++;
			taille = tab[i];
		}
		i --;
	}
	return (val == cpt);
}

int	test_col(int tab[4][4], int val, int row, int col)
{
	int	i;
	int	taille;
	int	cpt;	

	i = 0;
	taille = 0;
	cpt = 0;
	while (i <= row)
	{
		if (tab[i][col] > taille)
		{
			cpt ++;
			taille = tab[i][col];
		}
		i++;
	}
	return (cpt <= val && cpt >= val - (3 - row));
}

int	test_col_rev(int tab[4][4], int val, int nb_col)
{
	int	i;
	int	taille;
	int	cpt;

	i = 3;
	taille = 0;
	cpt = 0;
	while (i >= 0)
	{
		if (tab[i][nb_col] > taille)
		{
			cpt ++;
			taille = tab[i][nb_col];
		}
		i--;
	}
	return (val == cpt);
}
