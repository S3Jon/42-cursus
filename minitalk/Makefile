LIBFT = Libft/libft.a

CC = gcc
CCFLAGS = -Wall -Werror -Wextra

CLI = client
SRV = server

CLI_SRCS = client.c
SRV_SRCS = server.c

OBJS_CLI = $(CLI_SRCS:.c=.o)
OBJS_SRV = $(SRV_SRCS:.c=.o)


all: $(SRV) $(CLI)

$(LIBFT):
		$(MAKE) -C ./libft
$(SRV) $(CLI): $(OBJS_SRV) $(OBJS_CLI) $(LIBFT)
		$(CC) $(CCFLAGS) $(OBJS_CLI) Libft/libft.a -o $(CLI)
		$(CC) $(CCFLAGS) $(OBJS_SRV) Libft/libft.a -o $(SRV)


clean:	
		$(MAKE) clean -C ./Libft
		rm -rf *.o

fclean:	clean
		$(MAKE) fclean -C ./libft
		rm -rf $(CLI) $(SRV) 

re:	fclean all
