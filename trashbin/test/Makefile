# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 18:50:05 by bsamzun           #+#    #+#              #
#    Updated: 2024/10/06 18:56:58 by bsamzun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	./main.c \
		./ft_assign_all.c \
		./ft_split.c \
		./ft_print_whole_number.c \
		./ft_print_tens_and_less.c \
		./ft_print_hundreds_and_more.c \

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Werror -Wextra

NAME = rush-02

all:$(NAME)

$(NAME):$(OBJ)
		cc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)
