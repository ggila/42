/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 01:54:54 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/05 11:40:14 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H

# include "libft.h"
# include "str_error.h"
# include "mlx.h"
# include <stdlib.h>

# define OK 0
# define KO -1
# define STOP 1

# define RED 0xff0000
# define WHITE 0xffffff
# define WIDTH 1200
# define HEIGHT 1200
# define TITLE "ggilaber"

# define A g_monom[2]
# define B g_monom[1]
# define C g_monom[0]

# define USAGE "usage : ./computor [-tf] equ"
# define LEGAL "\t +-*=^,.0123456789"
# define SEPARATOR "+="
# define MASK 1
# define MASK_VISUAL MASK<<1
# define MASK_FLAG MASK<<2
# define MASK_DEBUG MASK<<3

# define MASK_N1 MASK
# define MASK_MINUS MASK<<1
# define MASK_X MASK<<2
# define MASK_EQUAL MASK<<3
# define MASK_TOTAL MASK<<4

# define IS(f) (f & g_flag)
# define SKIP(str) (str - g_str_init)

# define ABS(n) (((n) > 0) ? (n) : (-n))

char			g_x;
int				g_flag;
char			g_flag_op;
char			*g_str_init;
double			g_monom[4];

/*
** get_coef.c
*/

void			ft_get_values(char *str);

/*
** mlx.c
*/

void			ft_mlx(char *str);

/*
** get_opt.c
*/

void			ft_get_opt(int *ac, char ***av);

/*
** ft_solve_three.c
*/

void			ft_solve_three(void);

/*
** ft_solve.c
*/

double			ft_sqrt(double d);
void			ft_solve(void);

/*
** toolbox.c
*/

double			ft_get_number(char *str, int i);
int				ft_end_power(char *str, int i);
char			ft_isseparator(char *str, int i);
int				ft_skip_space(char *str, int i);
int				ft_skip_monom(char *str, int i);
int				ft_skip_digit(char *str, int i);

/*
** main.c
*/

void			ft_quit(char *str, char *str2, char c, int n);
void			ft_parse(char *str);

/*
** ft_put.c
*/

void			ft_put_monom(int i);
void			ft_put_all_monom(void);
void			ft_print_flag(char n);
void			ft_put_double(double d);
void			ft_put_delta(double delta);
void			ft_put_sol(double delta);

/*
** get_opt.c
*/

void			ft_parse(char *str);

/*
** ft_check_input.c
*/

void			ft_check_input(char *str);
void			ft_check_nb_equal(char *str);
void			ft_check_eq(char *str);
void			ft_check_x(char *str);
void			ft_check_end(char *str);

#endif
