# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 14:51:46 by hlehmann          #+#    #+#              #
#    Updated: 2022/01/18 15:43:39 by vheymans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LFT = libft/

SRC =	main.c \
		util/path.c \
		util/cmd.c \
		util/input_handling/find_limitor.c \
		util/input_handling/input_parsing.c \

CC = gcc

CFLAGS = -Wall -Werror -Wextra -l readline

all: $(NAME)

$(NAME): $(SRC)
	make -C libft/
	$(CC) $(CFLAGS) $(SRC) $(LFT)libft.a -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LFT)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
