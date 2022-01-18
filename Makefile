# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 14:51:46 by hlehmann          #+#    #+#              #
#    Updated: 2022/01/18 16:41:17 by cdahlhof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LFT = ./libft/

SRC =	main.c \
		util/path.c \
		util/cmd.c \
		util/input_handling/find_limitor.c \
		util/input_handling/input_parsing.c \
		util/envy/unset.c \
		util/envy/utils.c \
		util/envy/export.c \
		util/envy/env.c \

CC = gcc

CFLAGS = -Wall -Werror -Wextra# -l readline

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
