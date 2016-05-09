# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/27 08:45:05 by ggilaber          #+#    #+#              #
#*   Updated: 2015/03/18 19:02:53 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re all

C_DEFAULT =		\033[0m
C_BLACK = 		\033[1;30m
C_GREY =		\033[1;37m

CC = gcc

FLAGS = -Wall -Werror -Wextra

FRAMEWORK =		-framework OpenGL\
				-framework AppKit

NAME = wolf3d

SRC_DIR = src

SRC = main.c\
		read_map.c\
		debug.c\
		draw.c\
		draw_modif.c\
		calcule_screen.c\
		vec_op.c\
		throw_ray.c\
		loop.c\
		wall_limit.c\
		motion.c

SRC_PATH = $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR = obj
OBJ = $(SRC:.c=.o)
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))

INC = -I./libft/inc\
		-I./inc\
		-I./minilibx_macos

LIB = -L./libft/ -lft\
		-L./minilibx_macos -lmlx

LIB_LIST = libft/libft.a\
		   minilibx_macos/libmlx.a

LIB_INC = .libft/inc/libft.h

HEADER = $(addprefix $(inc), $(NAME).h)

all : $(NAME)

$(NAME) : $(OBJ_PATH) libft/libft.a minilibx_macos/lmlx.a
	@echo "gcc -f -o $(NAME) .o -L"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ_PATH) $(LIB) $(FRAMEWORK)

libft/libft.a :
	@make -C libft/

minilibx_macos/lmlx.a :
	@echo "$(C_BLACK)make minilibx $(C_DEFAULT)"
	@make -C minilibx_macos/

echo_make :
	@echo "$(C_WHITE)make ./$(NAME)$(C_DEFAULT)"

$(LIBA) :
	@make -C libft/

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@echo "\t$(C_BLACK)gcc -f -c $^ -o .o$(C_DEFAULT)"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INC) -c $^ -o $@

clean :
	@echo "$(C_BLACK)rm -rf ./$(OBJ_DIR)/$(C_DEFAULT)"
	@rm -rf $(OBJ_PATH)

cleanlib :
	make clean -C libft/

fclean : fcleanlib clean
	@echo "$(C_BLACK)rm -rf ./$(NAME)$(C_DEFAULT)"
	@rm -rf $(NAME)

fcleanlib :
	@make fclean -C libft/

re : fclean all

sw :
	rm -rf */.*.sw[po]
	rm -rf ./inc/$(NAME).h.gch
	rm -rf ./libft/inc/libft.h.gch
