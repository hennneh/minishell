SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putnbrbase.c \
			ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
			ft_substr.c ft_tolower.c ft_toupper.c get_next_line.c get_next_line_utils.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_error.c\
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_del.c \
			ft_free_2dstr.c \

INCLUDES = get_next_line.h libft.h
OBJECTS = $(SOURCES:.c=.o)
OBJECTS_B = $(SOURCES_B:.c=.o)

FLAGS = -Wall -Werror -Wextra

NAME = libft.a

all: $(NAME)

$(NAME): $(SOURCES)
	gcc $(FLAGS) -c $(SOURCES)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	$(MAKE) clean

bonus: $(NAME) 
	gcc $(FLAGS) -I$(INCLUDES) -c $(SOURCES_B)
	ar rc $(NAME) $(OBJECTS_B)
	ranlib $(NAME)
	$(MAKE) cleanb

clean:
	rm -rf $(OBJECTS)

cleanb:
	rm -rf $(OBJECTS_B)
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re