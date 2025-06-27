# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jianisong <jianisong@student.codam.nl>       +#+                      #
#                                                    +#+                       #
#    Created: 2024/11/21 14:06:44 by jianisong     #+#    #+#                  #
#    Updated: 2025/06/27 14:20:51 by jianisong     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Basic settings
NAME	:= fractol
CC 		:= cc
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -O3 -ffast-math -g
LDFLAGS := -ldl -lglfw -pthread -lm
LIBMLX_DIR	:= ./lib/MLX42
LIBFT_DIR   := ./lib/libft
HEADERS 	:= ./include/fractol.h
SRCS	:= ./src/calculation.c \
			./src/color.c \
			./src/color_palette.c \
			./src/hooks.c \
			./src/init.c \
			./src/main.c \
			./src/parse_args.c \
			./src/utils.c \
			./src/view.c 
OBJS	:= ${SRCS:.c=.o}

# Library paths
LIBMLX	:= $(LIBMLX_DIR)/build/libmlx42.a 
LIBFT   := $(LIBFT_DIR)/libft.a

# Include paths
INCLUDE_PATHS	:= -I ./include -I $(LIBMLX_DIR)/include -I $(LIBFT_DIR)

# Main target
all: $(NAME)

# Build fractol
$(NAME): $(LIBMLX) $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBMLX) $(LIBFT) $(INCLUDE_PATHS) $(LDFLAGS) -o $(NAME)
	@echo "\033[32m[✓] $(NAME) compiled successfully\033[0m" 
	
# Build libmlx
$(LIBMLX):
	@cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && make -C $(LIBMLX_DIR)/build -j4

# Build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

#Compile source files
%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) $(INCLUDE_PATHS) -o $@ -c $<  
	@echo "\033[34m Compiling: $(notdir $<)\033[0m"

clean:
	@echo "\033[31m[*] Cleaning project build files...\033[0m"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(LIBMLX_DIR)/build
	@rm -rf $(OBJS) $(BONUS_OBJS)
	@echo "\033[32m[✓] Object files and build directories cleaned\033[0m"

fclean: clean
	@echo "\033[31m[*] Removing executable and final artifacts...\033[0m"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME) $(NAME)_bonus
	@echo "\033[32m[✓] Project fully cleaned\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re