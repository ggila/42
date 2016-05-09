/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_proto.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 18:04:00 by ggilaber          #+#    #+#             */
/*   Updated: 2015/03/18 18:05:43 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_PROTO_H
# define FRACTOL_PROTO_H

int			ft_set_color(t_spec *spec, int i);
int			ft_is_num(int key);
int			ft_is_dir(int key);
int			ft_is_key(int key);
void		ft_raa(int keycode, t_spec *spec);
t_complex	ft_inv(t_complex z);
t_complex	ft_mult(t_complex y, t_complex z);
t_complex	ft_pow(t_complex z, int n);
void		ft_get_zero(t_complex zero[20], int n);
void		ft_init_julia_spec(t_env *env, char fractal);
void		ft_init_mandel_spec(t_env *env, char fractal);
void		ft_init_spec(t_env *env, char fractal);
void		ft_init_color(t_env *env);
int			ft_expose_hook(t_env *env);
int			ft_key_hook(int keycode, t_env *env);
int			ft_mouse_hook(int button, int x, int y, t_env *env);
int			ft_loop_hook(t_env *env);
int			ft_motion_leftmouse(int x, int y, t_env *env);
int			ft_motion_key(int keycode, t_env *env);
int			ft_press_key(int keycode, t_env *env);
void		ft_change_speed(t_spec *spec, char fast);
void		ft_change_color(t_spec *spec, int keycode);
void		ft_change_fractal(t_env *env, int keycode);
void		ft_swap_display(t_spec *spec);
void		ft_key_julia(int keycode, t_spec *spec);
void		ft_key_motion_julia(int keycode, t_spec *spec);
void		ft_motion_leftmouse_julia(int x, int y, t_spec *spec);
void		ft_key_mandel(int keycode, t_spec *spec);
void		ft_key_motion_mandel(int keycode, t_spec *spec);
void		ft_motion_leftmouse_mandel(int x, int y, t_spec *spec);
int			ft_grad(t_spec *spec, int i, double norm);
int			ft_julia(t_spec *spec, int x, int y);
int			ft_mandel(t_spec *spec, int x, int y);
int			ft_newton(t_spec *spec, int x, int y);
void		ft_iterate(t_env *env);
void		ft_sierpi(t_env *env);
double		ft_norm(t_complex z);
t_complex	ft_sqr(t_complex z);
int			ft_eq_mandel(t_complex z, t_complex seed, t_spec *spec);
void		ft_print_spec(t_env env);
void		ft_print_mouse(t_spec spec, int button, int x, int y);

#endif
