# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/18 13:08:14 by jsaglio           #+#    #+#              #
#    Updated: 2015/03/18 13:29:11 by jsaglio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOM =		libmlx.a
SRC =		mlx_shaders.c\
			mlx_new_window.m\
			mlx_init_loop.m\
			mlx_new_image.m\
			mlx_xpm.c\
			mlx_int_str_to_wordtab.c
OBJ1 =		$(SRC:.c=.o)
OBJ =		$(OBJ1:.m=.o)
CFLAGS +=	-O2

all: $(NOM)

$(NOM):	$(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NOM)

re: clean all
