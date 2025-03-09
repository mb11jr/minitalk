CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory
MAKE = make -C
CLIENT_SRC = client.c
SERVER_SRC = server.c
CLIENT_SRC_BONUS = client_bonus.c
SERVER_SRC_BONUS = server_bonus.c
UTILS = utils.c
LIBFT = libft/libft.a
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

all : $(CLIENT) $(SERVER)

bonus : $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT) : $(CLIENT_SRC) $(LIBFT)
	@echo "🔄 Compiling $(CLIENT_SRC) ..."
	@$(CC) $(CFLAGS) $(CLIENT_SRC) $(UTILS) $(LIBFT) -o $@
	@echo "[$(CLIENT)] created successfully! ✅"

$(SERVER) : $(SERVER_SRC) $(LIBFT)
	@echo "🔄 Compiling $(SERVER_SRC) ..."
	@$(CC) $(CFLAGS) $(SERVER_SRC) $(UTILS) $(LIBFT) -o $@
	@echo "[$(SERVER)] created successfully! ✅"

$(CLIENT_BONUS) : $(CLIENT_SRC_BONUS) $(LIBFT)
	@echo "🔄 Compiling $(CLIENT_SRC_BONUS) ..."
	@$(CC) $(CFLAGS) $(CLIENT_SRC_BONUS) $(UTILS) $(LIBFT) -o $@
	@echo "[$(CLIENT_BONUS)] created successfully! ✅"

$(SERVER_BONUS) : $(SERVER_SRC_BONUS) $(LIBFT)
	@echo "🔄 Compiling $(SERVER_SRC_BONUS) ..."
	@$(CC) $(CFLAGS) $(SERVER_SRC_BONUS) $(UTILS) $(LIBFT) -o $@
	@echo "[$(SERVER_BONUS)] created successfully! ✅"

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
	@rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@echo "✨ Full clean complete!"

re: fclean all

.PHONY : all clean fclean re bonus