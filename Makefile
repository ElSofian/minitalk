# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 19:46:45 by soelalou          #+#    #+#              #
#    Updated: 2023/12/03 15:19:54 by soelalou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# VARIABLES

NAME        = minitalk.a
LIBFT		= libft/libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf

CLIENT      = client
SERVER      = server
CLIENTB		= client_bonus
SERVERB		= server_bonus

CLIENT_SRC  = src/client.c
SERVER_SRC  = src/server.c
CLIENTB_SRC	= src/client_bonus.c
SERVERB_SRC	= src/server_bonus.c

OBJ_DIR     = bin
CLIENT_OBJ	= $(addprefix $(OBJ_DIR)/, $(CLIENT_SRC:.c=.o))
SERVER_OBJ	= $(addprefix $(OBJ_DIR)/, $(SERVER_SRC:.c=.o))
CLIENTB_OBJ	= $(addprefix $(OBJ_DIR)/, $(CLIENTB_SRC:.c=.o))
SERVERB_OBJ	= $(addprefix $(OBJ_DIR)/, $(SERVERB_SRC:.c=.o))


# **************************************************************************** #
# COLORS

GREEN       = \033[0;32m
GREY        = \033[1;30m
PURPLE      = \033[0;35m
BLUE        = \033[0;94m
CYAN        = \033[0;35m
PINK        = \033[0;35m
END_COLOR   = \033[0;39m


# **************************************************************************** #
# RULES

dependencies:
	@make -s -C libft
	@make -s all

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	@echo "$(GREEN)[Minitalk]$(END_COLOR) Client is ready!"
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) -I inc $(LIBFT) -o $(CLIENT)

$(SERVER): $(SERVER_OBJ)
	@echo "$(GREEN)[Minitalk]$(END_COLOR) Server is ready!"
	@$(CC) $(CFLAGS) $(SERVER_OBJ) -I inc $(LIBFT) -o $(SERVER)

bonus: $(CLIENTB) $(SERVERB)

$(CLIENTB): $(CLIENTB_OBJ)
	@echo "$(GREEN)[Minitalk]$(END_COLOR) Client with bonus is ready!"
	@$(CC) $(CFLAGS) $(CLIENTB_OBJ) -I inc $(LIBFT) -o $(CLIENTB)

$(SERVERB): $(SERVERB_OBJ)
	@echo "$(GREEN)[Minitalk]$(END_COLOR) Server with bonus is ready!"
	@$(CC) $(CFLAGS) $(SERVERB_OBJ) -I inc $(LIBFT) -o $(SERVERB)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I inc -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@make clean -s -C libft
	@echo "$(GREY)[Clean]$(END_COLOR) Objects have been deleted !"

fclean: clean
	@$(RM) bin $(CLIENT) $(SERVER) $(CLIENTB) $(SERVERB)
	@echo "$(GREY)[Clean]$(END_COLOR) $(NAME) and executables have been deleted !"

re: fclean all
	@echo "$(PURPLE)[Rebuild]$(END_COLOR) Done !"

.PHONY: all clean fclean re
