/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_define.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 01:07:38 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/23 14:00:56 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx_encoding.h"
# include <X.h>

# define OK 0
# define KO 1
# define TITLE "ggilaber"

# define PI 3.1416

# define IM_WIDTH 600
# define IM_HEIGHT 400
# define MAP_WIDTH 20
# define MAP_HEIGHT 20

# define NORTH 1
# define SOUTH 2
# define EST 3
# define WEST 4
# define NORTH_COLOR 0x00006699
# define SOUTH_COLOR 0x00009966
# define EST_COLOR 0x00660033
# define WEST_COLOR 0x00EE8800
# define GROUND_COLOR 0x00000033
# define SKY_COLOR 0x00CCCCCC

# define BLACK 0x00000000
# define RED 0x00BBBBBB
# define WHITE 0x00FFFFFF

# define RIGHT_CLICK 3
# define LEFT_CLICK 1

# define X 0
# define Y 1

# define ABS(n) (((n) > 0) ? (n) : -(n))

# define MASK			1U
# define MASK_DRAW		MASK<<0
# define MASK_MAP		MASK<<1

typedef struct	s_pt
{
	double		x;
	double		y;
}				t_pt;

typedef struct	s_ray
{
	double		len;
	double		ray_step[2];
	double		ray_mapcase[2];
	int			map_pos[2];
	int			map_step[2];
	char		wall_face;
}				t_ray;

typedef struct	s_feed
{
	double		dist;
	char		face;
	int			ground;
	int			sky;
}				t_feed;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			bypp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_pt		pos;
	t_pt		dir;
	t_pt		screen_pos;
	t_pt		screen_dir;
	int			flag;
	int			ang;
}				t_env;

char			g_map[MAP_HEIGHT][MAP_WIDTH];
double			g_cos[3600];
double			g_sin[3600];
int				g_po[2];

int				read_map(void);

void			debug_pt(t_pt pt);
void			debug_env(t_env *env);
void			debug_feedback(t_feed feedback);
void			debug_map(void);
void			print_float(double f);

int				ft_expose_hook(t_env *env);
int				ft_loop_hook(t_env *env);

int				ft_motion_key(int keycode, t_env *env);

void			draw_map(t_env *env);
void			draw_pos(t_pt pos, t_env *env);
void			draw_image(t_env *env);

void			calcule_screen(t_env *env);

int				get_sky_limit(double dist);
int				get_ground_limit(double dist);
t_feed			get_feedback(t_env *env, t_pt ray);

t_feed			throw_ray(t_pt pos, t_pt ray, int ang, double d_ang);

double			ft_norm(t_pt pt);
t_pt			ft_dot(double a, t_pt v1);
t_pt			ft_add(t_pt v1, t_pt v2);

void			draw_modif(t_env *env);

#endif
