# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/05 15:19:42 by ggilaber          #+#    #+#              #
#    Updated: 2015/10/07 17:50:54 by ggilaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re all

C_DEFAULT =		\033[0m
C_BLACK = 		\033[1;30m
C_GREY =		\033[1;37m

CC = nasm

FLAGS = -f macho64

NAME = libfts.a

SRC_DIR = src
SRC = ft_bzero.s\
	  ft_strcat.s\
	  ft_isalpha.s\
	  ft_isdigit.s\
	  ft_isalnum.s\
	  ft_isdigit.s\
	  ft_isascii.s\
	  ft_isprint.s\
	  ft_toupper.s\
	  ft_tolower.s\
	  ft_strlen.s\
	  ft_puts.s\
	  ft_memset.s\
	  ft_memcpy.s\
	  ft_strdup.s\
	  ft_cat.s
SRC_PATH = $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR = obj
OBJ = $(SRC:.s=.o)
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))

INC = -I./inc

all : $(NAME)

$(NAME) : $(OBJ_PATH)
	ar rc  $(NAME) $(OBJ_PATH)
	ranlib $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	@mkdir -p obj
	$(CC) $(FLAGS) $^ -o $@

clean :
	rm -rf obj/

fclean : clean
	rm -rf $(NAME)

re : fclean all

