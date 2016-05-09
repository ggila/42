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

HOSTTYPE ?= $(shell uname -m)_$(shell uname -s)

C_DEFAULT =		\033[0m
C_BLACK = 		\033[1;30m
C_GREY =		\033[1;37m

CC = gcc

FLAGS = -Wall -Werror -Wextra

#NAME = malloc
NAME = libft_malloc_$(HOSTTYPE).so

SRC_DIR = src

SRC = malloc.c\
	  free.c\
	  realloc.c\
	  show_alloc_mem/show_alloc_mem.c\
	  show_alloc_mem/show_region.c\
	  show_alloc_mem/show_region_deb.c\
	  region/fromnewregion.c\
	  region/fromregions.c\
	  region/setnewregion.c\
	  block/setblock.c\
	  block/blockregion.c\
	  block/checkaroundblock.c\
	  block/setfreeblock.c\
	  block/enlargeblock.c\
	  lib/ft_memcpy.c\
	  lib/ft_putptr.c\
	  lib/ft_putendl.c\
	  lib/ft_print.c\
	  lib/ft_putchar.c\
	  lib/ft_putnbr.c\
	  lib/ft_env.c

#OBJ_DIR = obj/region obj/block obj/lib

#SRC = malloc.c\
#	  fromnewregion.c\
#	  fromregions.c\
#	  setnewregion.c\
#	  show_alloc_mem.c\
#	  setblock.c\
#	  ft_putendl.c

SRC_PATH = $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR = obj
OBJ = $(SRC:.c=.o)
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))

INC = -I./libft/inc\
		-I./inc\

#LIB = -L./libft/ -lft

#LIB_INC = .libft/inc/libft.h

HEADER = $(addprefix $(inc), $(NAME).h)

all : $(NAME)

$(NAME) : $(OBJ_PATH)
	@echo "gcc -f -o $(NAME) .o -L"
	@$(CC) $(FLAGS) -shared -o $(NAME) $(OBJ_PATH) $(LIB)
	@rm -f libft_malloc.so
	@ln -s $(NAME) libft_malloc.so

libft/libft.a :
	@make -C libft/

echo_make :
	@echo "$(C_WHITE)make ./$(NAME)$(C_DEFAULT)"

$(LIBA) :
	@make -C libft/

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@echo "\t$(C_BLACK)gcc -f -c $^ -o .o$(C_DEFAULT)"
	@mkdir -p obj/region obj/block obj/lib obj/show_alloc_mem
#	@echo "\t$(C_BLACK)gcc -flag -I./inc/ -c $^ -o $@$(C_DEFAULT)"
	@$(CC) $(FLAGS) $(INC) -c $^ -o $@

clean :
	@echo "$(C_BLACK)rm -rf ./$(OBJ_DIR)/$(C_DEFAULT)"
	@rm -rf $(OBJ_PATH)

fclean : clean
	@echo "$(C_BLACK)rm -rf ./$(NAME)$(C_DEFAULT)"
	@rm -rf $(NAME)
	@rm -rf libft_malloc.so

re : fclean all

sw :
	rm -rf **/.*.sw[po]
	rm -rf **/.*.h.gch
	rm -rf ./inc/$(NAME).h.gch

test :
	gcc -o test.out test.c
