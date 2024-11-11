# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 21:59:42 by bsamzun           #+#    #+#              #
#    Updated: 2024/10/09 22:08:51 by bsamzun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

SRC =	ft_do_op.c \
		ft_op.c

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	cc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY:all clean fclean re
