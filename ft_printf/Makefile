# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 17:10:29 by jonsanch          #+#    #+#              #
#    Updated: 2022/11/14 18:20:06 by jonsanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

MAIN_SRC := ft_printf.c ft_aux.c ft_aux2.c

MAIN_OBJ = $(MAIN_SRC:.c=.o)

# INCLUDE = ft_ftprintf.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $(MAIN_SRC)

all: $(NAME)

$(NAME): $(MAIN_OBJ) $(INCLUDES)
	ar rcs $(NAME) $(MAIN_OBJ)


clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
