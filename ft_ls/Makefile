# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/27 08:45:05 by ggilaber          #+#    #+#              #
#    Updated: 2015/01/21 22:15:38 by ggilaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re all

CC = gcc

FLAGS = -Wall -Werror -Wextra -g3

NAME = ft_ls

SRC = main.c getopt.c mergesort_array.c ft_cmp.c ft_cmp2.c dir.c ft_print.c\
	  toolbox.c opt.c ft_check.c tab_dir.c long_format.c ft_putl.c ft_putl2.c\
	  sort_key.c

OBJ = $(SRC:.c=.o)

INC = -I./libft/includes

LIB = -L./libft/ -lft

LIBA = ./libft/libft.a

all : $(NAME)

$(NAME) : $(LIBA) $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

$(LIBA) :
	make -C libft/

%.o : %.c
	$(CC)  $(FLAGS) $(INC) -c $^

clean : cleanlib
	rm -rf $(OBJ)

cleanlib :
	make clean -C libft/

fclean : clean fcleanlib
	rm -rf $(NAME)

fcleanlib :
	make fclean -C libft/

re : fclean all
