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

NAME = fractol

SRC_DIR = src
SRC = complex.c\
		complex_op.c\
		debug.c\
		define.c\
		env_modif.c\
		iteration.c\
		init_spec.c\
		loop.c\
		loop_julia.c\
		loop_mandel.c\
		main.c\
		motion.c\
		print_fract.c

SRC_PATH = $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR = obj
OBJ = $(SRC:.c=.o)
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))

INC = -I./libft/inc\
		-I/usr/X11/include\
		-I./inc

LIB = -L./libft/ -lft\
		-L/usr/X11/lib -lmlx -lXext -lX11\

LIB_INC = .libft/inc/libft.h

HEADER = $(addprefix $(inc), $(NAME).h)

all : $(NAME)

$(NAME) : $(OBJ_PATH) libft/libft.a
	@echo "gcc -f -o $(NAME) .o -L"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ_PATH) $(LIB)

libft/libft.a :
	@make -C libft/

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
	rm -rf **/.*.sw[po]
	rm -rf ./inc/$(NAME).h.gch
	rm -rf ./libft/inc/libft.h.gch
