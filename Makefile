# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 14:51:46 by hlehmann          #+#    #+#              #
#    Updated: 2022/02/02 16:59:37 by cdahlhof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LFT = ./libft/

SRC =	main.c \
		util/henne/path.c \
		util/henne/cmd.c \
		util/henne/pwd.c \
		util/henne/prompt.c \
		util/whitespace.c \
		util/doller.c \
		util/input_handling/find_limitor.c \
		util/input_handling/input_parsing.c \
		util/input_handling/pipe_split.c \
		util/input_handling/cmd_split.c \
		util/envy/env.c \
		util/envy/re_envent.c

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
