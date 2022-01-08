# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 14:51:46 by hlehmann          #+#    #+#              #
#    Updated: 2022/01/08 13:28:11 by kchaniot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LFT = libft/

SRC =	main.c \
		util/path.c 

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
