/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 19:27:18 by ggilaber          #+#    #+#             */
/*   Updated: 2015/03/18 18:11:32 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCT_H
# define FRACTOL_STRUCT_H

typedef struct	s_complex
{
	double		a;
	double		b;
}				t_complex;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			bypp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_spec
{
	char		fractal;
	int			nb_it;
	int			color[3];
	char		modif;
	double		coef_col[3][3];
	double		delta;
	t_complex	root;
	double		x_mid;
	double		y_mid;
	double		x_mouse;
	double		y_mouse;
	double		theta;
	double		x_amp;
	int			power;
	t_complex	zero[20];
	char		fast;
	char		flag;
}				t_spec;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_spec		spec;
	char		flag;
}				t_env;

typedef void	(*t_ft_mouse)(int, int, t_spec*);
typedef void	(*t_ft_key)(int, t_spec*);
typedef int		(*t_ft_get_pix)(t_spec*, int, int);
typedef void	(*t_ft_env_init_fract)(t_env*, char);

#endif
