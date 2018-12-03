#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/11 12:09:36 by yzavhoro          #+#    #+#              #
#    Updated: 2018/05/13 17:40:49 by yzavhoro         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME := jen9shell

LIB_DIR := ./libftprintf/
SRC_DIR := ./srcs/
OBJ_DIR := ./objects/
INC_DIR := ./incs/

SRCS := main.c ft_env.c ft_setenv.c ft_cd.c utils.c
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC := gcc
#FLAGS := -Wall -Wextra -Werror

LIBFT = $(LIB_DIR)libftprintf.a
LIBFT_FLAGS := -L $(LIB_DIR) -lft
LIBFT_INC := $(LIB_DIR)includes

HDR_FLAGS := -I $(LIBFT_INC) -I $(INC_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(FLAGS) $(HDR_FLAGS) -o $(NAME) $(LIBFT)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $< -o $@ $(FLAGS) $(HDR_FLAGS)

$(LIBFT):
	make -C $(LIB_DIR)

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJ)

fclean:
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all
