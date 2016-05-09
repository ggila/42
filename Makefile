# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/27 08:45:05 by ggilaber          #+#    #+#              #
#*   Updated: 2015/04/05 08:04:28 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re all

C_DEFAULT =		\033[0m
C_BLACK = 		\033[1;30m
C_GREY =		\033[1;37m

CC = gcc

FLAGS = -Wall -Werror -Wextra

NAME = computor

SRC_DIR = src
SRC = main.c\
		get_opt.c\
		ft_put.c\
		ft_put2.c\
		ft_check_inputs.c\
		ft_check_inputs2.c\
		ft_get_coef.c\
		ft_quit.c\
		ft_solve.c\
		ft_solve_three.c\
		ft_itod.c\
		mlx.c\
		toolbox.c

SRC_PATH = $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR = obj
OBJ = $(SRC:.c=.o)
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))

INC = -I./libft/inc\
		-I./inc\
		-I./minilibx_macos

LIB = -L./libft/ -lft\
		-L./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

LIB_INC = .libft/inc/libft.h

HEADER = $(addprefix $(inc), $(NAME).h)

all : $(NAME)

$(NAME) : $(OBJ_PATH) libft/libft.a minilibx_macos/libmlx.a
	@echo "gcc -f -o $(NAME) .o -L"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ_PATH) $(LIB)

libft/libft.a :
	@make -C libft/

minilibx_macos/libmlx.a :
	@make -C minilibx_macos/

echo_make :
	@echo "$(C_WHITE)make ./$(NAME)$(C_DEFAULT)"

$(LIBA) :
	@make -C libft/

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@echo "\t$(C_BLACK)gcc -f -c $^ -o .o$(C_DEFAULT)"
	@mkdir -p obj
#	@echo "\t$(C_BLACK)gcc -flag -I./inc/ -c $^ -o $@$(C_DEFAULT)"
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
	rm -rf **/.*.sw[po]
	rm -rf ./inc/$(NAME).h.gch
	rm -rf ./libft/inc/libft.h.gch

