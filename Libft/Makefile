# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 16:54:50 by jonsanch          #+#    #+#              #
#    Updated: 2022/09/22 16:35:52 by jonsanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MAIN_SRC := ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_tolower.c ft_toupper.c \
	ft_bzero.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_atoi.c ft_calloc.c \
	ft_strdup.c ft_strjoin.c ft_itoa.c ft_substr.c ft_strtrim.c ft_putchar_fd.c ft_putnbr_fd.c \
	ft_putendl_fd.c ft_putstr_fd.c ft_strmapi.c ft_striteri.c ft_split.c 

BONUS_SRC := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c \
	ft_lstiter.c ft_lstdelone.c ft_lstclear.c ft_lstlast.c ft_lstmap.c

MAIN_OBJ = $(MAIN_SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)


CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $(MAIN_SRC) $(BONUS_SRC)

all: $(NAME)

$(NAME): $(MAIN_OBJ) $(INCLUDES)
	ar rcs $(NAME) $(MAIN_OBJ)

bonus: $(NAME)
	$(CC) $(CFLAGS) -c $(BONUS_SRC)
	ar rc $(NAME) $(BONUS_OBJ)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus