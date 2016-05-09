/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:31:30 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/07 22:46:51 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# define TPIX(x, y, z)				(t_pix){x, y, z}

typedef struct		s_image
{
	void			*img;
	char			*data;
	int				width;
	int				height;
	int				bpp;
	int				bypp;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_pix
{
	int				x;
	int				y;
	int				c;
}					t_pix;

int					ft_draw_pix(t_pix p, t_image *image);
int					ft_draw_square(t_pix pos, t_pix delta, t_image *img);
int					ft_draw_img(t_pix p, t_image *src, t_image *dst);
int					ft_draw_getc(int x, int y, int *buf, t_image *img);

#endif
