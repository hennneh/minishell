# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 14:51:46 by hlehmann          #+#    #+#              #
#    Updated: 2022/02/01 14:46:10 by vheymans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LFT = ./libft/

SRC =	main.c \
		util/henne/path.c \
		util/henne/cmd.c \
		util/henne/prompt.c \
		util/henne/pwd.c \
		util/path.c \
		util/cmd.c \
		util/whitespace.c \
		util/input_handling/find_limitor.c \
		util/input_handling/input_parsing.c \
		util/input_handling/pipe_split.c \
		util/input_handling/cmd_split.c \
		util/envy/unset.c \
		util/envy/utils.c \
		util/envy/export.c \
		util/envy/env.c \
		util/envy/input_reshuffle.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra -l readline

all: $(NAME)

$(NAME): $(SRC)
	make -C ./libft
	$(CC) $(CFLAGS) $(SRC) $(LFT)libft.a -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LFT)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
