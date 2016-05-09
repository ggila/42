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

NAME = ft_minishell3

SRC_DIR = src
SRC = main.c\
		init.c\
		init_env.c\
		ft_get_cmd.c\
		ft_read_line.c\
		prompt.c\
		heredoc.c\
		ft_new_line.c\
		ft_move_line.c\
		ft_tline.c\
		ft_rewrite.c\
		ft_handle_tilde.c\
		ft_check_end.c\
		key_map.c\
		env.c\
		quit.c\
		tools.c\
		tools2.c\
		tools3.c\
		handle_dir.c\
		ft_check_file.c\
		ft_cmd_explode.c\
		fleche.c\
		update_pos.c\
		basic_move.c\
		basic_move2.c\
		line_insert.c\
		ft_change_line.c\
		screen_insert.c\
		line_del.c\
		ft_write.c\
		hist.c\
		tab.c\
		ft_star.c\
		dir.c\
		exec_cmd.c\
		ft_do.c\
		ft_get_prog_path.c\
		builtin.c\
		un_set_env.c\
		ft_cd.c\
		ft_cd2.c\
		redir.c\
		ft_handle_redir.c\
		fd.c\
		pipe.c\
		t_pll.c\
		ft_hdll.c\
		plug_heredoc.c\
		wildcard.c\
		visual.c\
		debug.c\
		handle_par.c

SRC_PATH = $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR = obj
OBJ = $(SRC:.c=.o)
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))

INC = -I./libft/inc\
		-I./inc\

LIB = -L./libft/ -lft\
		-ltermcap

LIB_INC = .libft/inc/libft.h

HEADER = $(addprefix $(inc), $(NAME).h)

all : $(NAME)

$(NAME) : $(OBJ_PATH) libft/libft.a inc/sh3.h
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
	rm -rf **/.*.h.gch
	rm -rf ./inc/$(NAME).h.gch

