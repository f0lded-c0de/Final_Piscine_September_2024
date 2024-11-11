# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 12:00:35 by ale-tell          #+#    #+#              #
#                                                                              #
# **************************************************************************** #

NAME = bsq
DEBUG_NAME = debug_bsq

C_DIR = srcs
U_DIR = utils
H_DIR = includes
CC = cc

SRC =	$(C_DIR)/$(U_DIR)/ft_atoi.c \
		$(C_DIR)/$(U_DIR)/ft_split.c \
		$(C_DIR)/$(U_DIR)/ft_string.c \
		$(C_DIR)/$(U_DIR)/ft_strcmp.c \
		$(C_DIR)/reader.c \
		$(C_DIR)/parser.c \
		$(C_DIR)/print_sol.c \
		$(C_DIR)/solver.c \
		$(C_DIR)/bsq.c

CFLAGS = -Wall -Wextra -Werror -I./$(H_DIR)

OBJ = $(SRC:.c=.o)

all: $(NAME)

test : $(NAME)
	clear && ./$(NAME) maps/test.map

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) 

gdb: $(DEBUG_NAME) 
	gdb $(DEBUG_NAME) 

$(DEBUG_NAME): $(SRC)
	$(CC) $(CFLAGS) -g $(SRC) -o $(DEBUG_NAME)

debug: $(DEBUG_NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all debug gdb debug
