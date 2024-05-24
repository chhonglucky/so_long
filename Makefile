# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 16:33:02 by chanhhon          #+#    #+#              #
#    Updated: 2024/05/24 20:49:11 by chanhhon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			=	cc
CFLAGS 		=	-Wall -Wextra -Werror
NAME 		=	so_long
SRC_NAME 	=	check_map_basic.c check_map_dfs.c csfunc.c free_func.c \
				init_img.c main.c map_parsing.c movement.c \

SRCS		=	$(addprefix $(SOURCE)/,$(SRC_NAME))
MLX		 	=	-lmlx -framework OpenGL -framework Appkit -Imlx
SOURCE		=	./srcs

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C ./Libft
	@$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(SRCS) ./Libft/libft.a
	
clean :
	@make -C ./Libft clean
	@rm -rf $(OBJS)

fclean :	clean
	@make -C ./Libft fclean
	@rm -rf $(NAME)

re :
	make fclean
	make	all

.PHONY : re fclean clean all bonus