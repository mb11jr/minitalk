CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory
MAKE = make -C
CLIENT_SRC = client.c
SERVER_SRC = server.c
CLIENT_NAME = client
SERVER_NAME = server
LIBFT = libft/libft.a

all : $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME) : $(CLIENT_SRC) $(LIBFT)
	@echo "🔄 Compiling $(CLIENT_SRC) ..."
	@$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIBFT) -o $@
	@echo "[$(CLIENT_NAME)] created successfully! ✅"

$(SERVER_NAME) : $(SERVER_SRC) $(LIBFT)
	@echo "🔄 Compiling $(SERVER_SRC) ..."
	@$(CC) $(CFLAGS) $(SERVER_SRC) $(LIBFT) -o $@
	@echo "[$(SERVER_NAME)] created successfully! ✅"

$(LIBFT):
	@echo "Building libft... ⏳"
	@$(MAKE) libft
	@echo "libft.a is up to date! ✅"

clean:
	@echo "Cleaning libft object files... 🧹 "
	@$(MAKE) libft clean
	@echo "✨ Clean complete!"

fclean: clean
	@echo "Removing binaries... 🗑️"
	@$(MAKE) libft fclean
	@rm -f $(CLIENT_NAME) $(SERVER_NAME)
	@echo "✨ Full clean complete!"

re: fclean all

.PHONY : all clean fclean re