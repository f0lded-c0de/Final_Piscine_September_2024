# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 19:43:54 by bsamzun           #+#    #+#              #
#    Updated: 2024/10/07 21:11:16 by bsamzun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	srcs/ft_putchar.c \
		srcs/ft_putstr.c \
		srcs/ft_strcmp.c \
		srcs/ft_strlen.c \
		srcs/ft_swap.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Werror -Wextra -I./includes

NAME = libft.a

all:$(NAME)

$(NAME):$(OBJ)
		ar rcs libft.a srcs/*.o

clean:
		rm -f $(OBJ)

fclean:clean
		rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re
