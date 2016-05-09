/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_define.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 01:07:38 by ggilaber          #+#    #+#             */
/*   Updated: 2015/03/18 18:07:34 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_DEFINE_H
# define FRACTOL_DEFINE_H

# include "fractol_define.h"
# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include "/usr/X11/include/X11/X.h"

# define OK 0
# define KO 1
# define TITLE "ggilaber"

# define PI 3.1416

# define JULIA 0
# define MANDEL 1
# define NEWTON 2
# define MEGALIA 3
# define MEGABROT 4

# define X_MANDEL -0.75
# define Y_MANDEL 0
# define X_AMP_MANDEL 3.2

# define X_JULIA 0.5
# define Y_JULIA 0
# define X_SEED_INIT 680
# define Y_SEED_INIT 280

# define X_NEWTON 0
# define Y_NEWTON 0
# define X_AMP_NEWTON 1.46
# define EPSILON 0.1
# define POWER 6

# define X_MOUSE_MOVE (WI / 4)
# define Y_MOUSE_MOVE (HI / 4)

# define WIDTH 533
# define HEIGHT 444

# define WI WIDTH
# define HI HEIGHT
# define WIM (WI / 3)
# define HIM HI
# define WIF (WI - WIM)
# define HIF HI
# define MID_WIF (WIM + WIF / 2.0)
# define MID_HIF (HIF / 2.0)
# define IM_MARGIN 30
# define HIMM (WIM * HI / WI)

# define TOMENU(j) ((j > 100) && (j < HI - 100))

# define COEF_RED_INIT_MANDEL_OUT2 1
# define COEF_BLUE_INIT_JULIA_IN 1
# define COEF_BLUE_INIT_JULIA_OUT2 1

# define IN 0
# define OUT1 1
# define OUT2 2
# define RED 0
# define GREEN 1
# define BLUE 2

# define THETA_INIT 0
# define INC_THETA 0.05

# define INC_COLOR 0.05
# define INC_DELTA 1.1
# define INC_NB_IT 1

# define INC_MOVE (5 * X_AMP_MANDEL / WIF)
# define INC_SEED 10

# define NB_IT_MANDEL 20
# define NB_IT_JULIA 30
# define NB_IT_NEWTON 20
# define MAX_MOD 4.0

# define KEY_A 97
# define KEY_F 102
# define KEY_M 109
# define KEY_R 114
# define KEY_Z 122
# define KEY_X 120
# define KEY_S 115
# define KEY_1 49
# define KEY_2 50
# define KEY_3 51
# define KEY_4 52
# define KEY_5 53
# define KEY_EQU 61
# define KEY_MIN 45
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEYPAD_0 65456
# define KEYPAD_1 65457
# define KEYPAD_2 65458
# define KEYPAD_3 65459
# define KEYPAD_4 65460
# define KEYPAD_5 65461
# define KEYPAD_6 65462
# define KEYPAD_7 65463
# define KEYPAD_8 65464
# define KEYPAD_9 65465
# define KEYPAD_PLUS 65451
# define KEYPAD_MINUS 65453
# define KEY_DEL 65535

# define RIGHT_CLICK 3
# define LEFT_CLICK 1

# define ABS(n) (((n) > 0) ? (n) : -(n))

# define MASK			1U
# define MASK_DRAW		MASK<<0
# define MASK_TWO		MASK<<1
# define MASK_KEY_PRESS	MASK<<2
# define MASK_SWAP		MASK<<3
# define MASK_MOVE		MASK<<4
# define MASK_BUT		MASK<<5
# define MASK_MENU		MASK<<6

#endif
