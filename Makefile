CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT_SRC = client.c
SERVER_SRC = server.c
CLIENT_NAME = client
SERVER_NAME = server

all : $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME) : $(CLIENT_SRC)
	make -C libft
	$(CC) $(CFLAGS) $(CLIENT_SRC) libft/libft.a -o $@

$(SERVER_NAME) : $(SERVER_SRC)
	make -C libft
	$(CC) $(CFLAGS) $(SERVER_SRC) libft/libft.a -o $@

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY : all clean fclean re