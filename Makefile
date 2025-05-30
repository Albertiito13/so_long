# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 15:45:42 by albcamac          #+#    #+#              #
#    Updated: 2025/05/29 18:05:01 by albcamac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === NOMBRE DEL EJECUTABLE ===
NAME	= so_long

# === DIRECTORIOS ===
SRCS_DIR	= src
INCLUDE_DIR	= include
MLX_DIR		= minilibx-linux
LIBFT_DIR	= libft

# === ARCHIVOS FUENTE ===
SRCS	= $(SRCS_DIR)/map_parser.c \
		  $(SRCS_DIR)/render.c \
		  $(SRCS_DIR)/map_utils.c \
		  $(SRCS_DIR)/events.c \
		  $(SRCS_DIR)/validate_map.c \
		  $(SRCS_DIR)/validate_utils.c \
		  so_long.c

OBJS	= $(SRCS:.c=.o)

# === LIBRERÍAS ===
LIBFT	= $(LIBFT_DIR)/libft.a
MLX		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# === COMPILADOR Y FLAGS ===
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# === REGLAS ===
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX) -L$(LIBFT_DIR) -lft

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re


