# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 11:26:33 by jsaglio           #+#    #+#              #
#    Updated: 2015/11/19 13:15:30 by jsaglio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:			clean fclean re all build nm

# Text format

CLEAR_LINE =	\r\033[A\033[2K
C_DEFAULT =		\033[0m
C_BLACK = 		\033[1;30m
C_RED = 		\033[1;31m
C_GREEN =		\033[1;32m
C_YELLOW =		\033[1;33m
C_BLUE =		\033[1;34m
C_PINK =		\033[1;35m
C_CYAN =		\033[1;36m
C_WHITE =		\033[1;37m
C_COLOR =		$(C_WHITE)

# Compilation info

NAME =			libft.a
CC =			gcc
CFLAG =			-Wall -Werror -Wextra -O2

INCS =			-I./includes
SRC_DIR =		srcs
OBJ_DIR =		objs

# ALL

all:			$(NAME)

# Build/Include object list and dependencies

-include		build.mk/object.mk
-include		build.mk/depend.mk

BUILD_DIR =		build.mk
BUILD_COMMAND =	makeBuildC
build:
				@rm -rf $(BUILD_DIR)
				@echo "$(C_COLOR)$(NAME) » Building dependencies$(C_DEFAULT)"
				@$(BUILD_COMMAND)

# Linking

$(NAME):		$(OBJS)
				@echo "$(C_COLOR)$(NAME) » linking$(C_DEFAULT)"
				@ar rc $(NAME) $(OBJS)
				@echo "$(CLEAR_LINE)$(C_COLOR)$(NAME) » archiving$(C_DEFAULT)"
				@ranlib $(NAME)
				@echo "$(CLEAR_LINE)$(C_COLOR)$(NAME) » linked$(C_DEFAULT)"

# Compiling

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				@mkdir -p $(dir $@)
				@echo "$(C_COLOR)$(NAME) » objects » $(C_DEFAULT)"$@
				@$(CC) $(CFLAG) $(INCS) -c $< -o $@

# Misc

clean:
				@rm -rf $(OBJ_DIR)

fclean:
				@rm -rf $(OBJ_DIR) $(NAME)

re:				fclean all

# Norminette

NORMINETTE =	norminette
nm:
				@echo "$(C_COLOR)$(NAME) » norminette$(C_DEFAULT)"
				@$(NORMINETTE) includes srcs
