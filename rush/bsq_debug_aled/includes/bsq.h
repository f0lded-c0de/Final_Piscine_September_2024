/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:33:02 by ale-tell          #+#    #+#             */
/*   Updated: 2024/10/08 16:21:28 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define READ_SIZE 1024

typedef struct s_sol
{
	int	y;
	int	x;
	int	size;
}	t_sol;

typedef struct s_map
{
	char	**lines;
	int		rows;
	int		columns;
	char	ob_char;
	char	em_char;
	char	fu_char;
}	t_map;

// atoi.c
int		ft_is_inset(char c, char *charset);
int		ft_atoi(char *str);

// ft_string.c
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_puterr(void);
char	*ft_strcpy(char *dest, char *str);

// ft_strcmp.c
int		ft_strcmp(char *s1, char *s2);

//read_file.c
char	*read_file(char *file_name);

// ft_parse_file.c
int		ft_parse_file(t_map *map, char *str);

// ft_plit.c
void	*free_split(char **words);
char	**ft_split(char *str, char *charset);

// pint_sol.c
void	print_sol(t_map *map, t_sol *sol);

// solv.c
void	solver(t_map *map, t_sol *sol, t_sol *best);

// bsq.c
int		free_map(t_map *map);
void	init_sol(t_sol *sol);

#endif
