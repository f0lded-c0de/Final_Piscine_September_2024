/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:33:02 by ale-tell          #+#    #+#             */
/*   Updated: 2024/10/08 11:34:20 by ale-tell         ###   ########.fr       */
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

typedef struct s_ob
{
	int		y;
	int		x;
}	t_ob;

typedef struct s_map
{
	char	**lines;
	int		rows;
	int		columns;
	t_ob	*ob_list;
	int		ob_count;
	char	ob_char;
	char	em_char;
	char	fu_char;
}	t_map;

// atoi.c
int		ft_atoi(char *str);

// base_utils.c
int		ft_is_inset(char c, char *charset);
int		ft_posinset(char c, char *charset);
int		ft_is_base_valid(char *base);
int		ft_is_whitespace(char c);

// ft_string.c
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_puterr(char *str);
char	*ft_strcpy(char *dest, char *str);

// ft_strcmp.c
int		ft_strcmp(char *s1, char *s2);

//read_file.c
char	*read_file(char *file_name);

// ft_parse_file.c
int		ft_parse_file(t_map *map, char *str);

// ft_plit.c
void	*free_split(char **words);
char	*ft_wrdcpy(char *str, char *charset);
int		ft_wordlen(char *str, char *charset);
char	**ft_split(char *str, char *charset);
int		ft_wordcount(char *str, char *charset);

// put_errors.c
void	*put_error_dict_ptr(void);
int		put_error_dict_int(void);
void	*put_error_ptr(void);
int		put_error_int(void);

// ft_math.h
int		ft_max(int x, int y);
int		ft_min(int x, int y);
int		isin_inter(int i, int min, int max);
int		isin_inter_strict(int i, int min, int max);

// pint_sol.c
void	print_sol(t_map *map, t_sol *sol);

// find_obstacles.c
t_map	*find_obstacles(t_map *map);

// solv.c
void	solver(t_map *map, t_sol *sol, t_sol *best);

// map_utlis.c
int		free_map(t_map *map);
int		ft_is_charset(char c, t_map *map);
void	init_sol(t_sol *sol);

#endif
