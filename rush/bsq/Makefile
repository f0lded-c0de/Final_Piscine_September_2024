# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 12:00:35 by ale-tell          #+#    #+#              #
#    Updated: 2024/10/07 11:55:31 by bsamzun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

C_DIR = srcs
H_DIR = includes
CC = cc

SRC =	$(C_DIR)/ft_atoi.c \
		$(C_DIR)/ft_base_utils.c \
		$(C_DIR)/ft_split.c \
		$(C_DIR)/ft_string.c \
		$(C_DIR)/put_errors.c \
		$(C_DIR)/read_file.c \
		$(C_DIR)/ft_parse_file.c \
		$(C_DIR)/ft_strcmp.c \
		$(C_DIR)/bsq.c

CFLAGS = -Wall -Wextra -Werror -I./$(H_DIR)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) 

debug : 
	$(CC) $(CFLAGS) -g $(SRC) && gdb ./a.out

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all debug
