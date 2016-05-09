/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 07:44:17 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/05 11:23:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static void	ft_trace_axes(void *mlx, void *win)
{
	int i;
	int j;

	i = 99;
	while (++i < 1100)
	{
		j = -5;
		mlx_pixel_put(mlx, win, i, 601, WHITE);
		mlx_pixel_put(mlx, win, i, 600, WHITE);
		if (i % 100 < 2)
			while (++j < 5)
				mlx_pixel_put(mlx, win, i, 600 + j, WHITE);
	}
	i = 99;
	while (++i < 1100)
	{
		j = -5;
		mlx_pixel_put(mlx, win, 601, i, WHITE);
		mlx_pixel_put(mlx, win, 600, i, WHITE);
		if (i % 100 < 2)
			while (++j < 5)
				mlx_pixel_put(mlx, win, 600 + j, i, WHITE);
	}
}

static void	ft_trace(void *mlx, void *win, char *str)
{
	int		i;
	double	d;
	int		border;

	border = WIDTH - 10 * (1 + ft_strlen((char*)str));
	ft_trace_axes(mlx, win);
	mlx_string_put(mlx, win, 10, 10, 0xffffff, (char*)str);
	mlx_string_put(mlx, win, border, 10, 0xffffff, (char*)str);
	mlx_string_put(mlx, win, 10, HEIGHT - 30, 0xffffff, (char*)str);
	mlx_string_put(mlx, win, border, HEIGHT - 30, 0xffffff, (char*)str);
	i = -1;
	while (++i < 1200)
	{
		d = ((double)i) / 100 - 6;
		d = g_monom[0] + g_monom[1] * d + g_monom[2] * d * d
		+ g_monom[3] * d * d * d;
		if (ABS(d) < 6)
			mlx_pixel_put(mlx, win, i, 600 - (int)(100 * d), RED);
	}
}

int			ft_motion_key(int key, void *e[])
{
	if (key == 53)
	{
		mlx_destroy_window(e[0], e[1]);
		exit(OK);
	}
	else if (key == 18 || key == 12)
		g_monom[0] += key == 18 ? 0.2 : -0.2;
	else if (key == 19 || key == 13)
		g_monom[1] += key == 19 ? 0.2 : -0.2;
	else if (key == 20 || key == 14)
		g_monom[2] += key == 20 ? 0.2 : -0.2;
	else if (key == 21 || key == 15)
		g_monom[3] += key == 21 ? 0.2 : -0.2;
	else if (key == 17)
	{
		mlx_destroy_window(e[0], e[1]);
		ft_memcpy(g_monom, e[3], 4 * sizeof(double));
		ft_mlx((char*)e[2]);
	}
	ft_solve();
	ft_trace(e[0], e[1], (char*)e[2]);
	ft_putstr("=================================================\n");
	return (OK);
}

void		ft_mlx(char *str)
{
	void	*mlx;
	void	*win;
	void	*e[4];
	double	c_monom[4];

	ft_memcpy(c_monom, g_monom, 4 * sizeof(double));
	if (!(mlx = mlx_init()))
		exit(KO);
	if (!(win = mlx_new_window(mlx, WIDTH, HEIGHT, TITLE)))
		exit(KO);
	e[0] = mlx;
	e[1] = win;
	e[2] = (void*)str;
	e[3] = (void*)c_monom;
	ft_trace(e[0], e[1], e[2]);
	mlx_key_hook(win, ft_motion_key, e);
	mlx_loop(mlx);
}
