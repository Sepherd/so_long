# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arecce <arecce@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 16:33:57 by arecce            #+#    #+#              #
#    Updated: 2022/11/04 15:30:50 by arecce           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra 

LIBFT = libft/libft.a

SRCS = so_long.c get_next_line.c get_next_line_utils.c map_check.c map_utils.c init.c \
		draw_map.c movement.c utils.c animation.c print_w_l.c

MLX = mlx/

HEADER = so_long.h

OBJS = $(SRCS:.c=.o)

LIB = ./libmlx.dylib

LIBS = -framework OpenGL -lm -framework AppKit

GREEN = \033[1;32m
RED = \033[1;31m
BLU = \033[1;34m
# YEL = \033[1;33m
# WHT = \033[1;37m
EOC = \033[1;0m


%.o: %.c
	@$(CC) -I ${MLX} -c $< -o $@

${NAME}: $(OBJS)
		@echo "$(BLU)Compiling libraries...$(EOC)"
		@${MAKE} -C libft
		@make -C mlx/
		@mv mlx/libmlx.dylib .
		@echo "$(GREEN)Libraries done.$(EOC)"
		@echo "$(BLU)Compiling so_long...$(EOC)"
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) $(LIBS) $(LIBFT)
		@echo "$(GREEN)So_long build completed.$(EOC)"
		
all: ${NAME}


clean:
		@echo "$(RED)Removing .o files...$(EOC)"
		@rm -f $(OBJS)
		@rm libmlx.dylib
		@${MAKE} -C libft clean
		@${MAKE} -C mlx clean
		@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
		@echo "$(RED)Removing the latest files...$(EOC)"
		@rm -f $(NAME)
		@${MAKE} -C libft fclean
		@echo "$(GREEN)Fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re