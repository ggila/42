/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:31:30 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/06 21:55:31 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUT_H
# define FT_PUT_H

# include "ft_typedef.h"
# include <unistd.h>

/*
**	String
*/

void		ft_putnl_fd(int fd);
void		ft_putnl(void);

void		ft_putchar_fd(char c, int fd);
void		ft_putchar(char c);

void		ft_putstr_fd(char const *s, int fd);
void		ft_putstr(char const *s);

void		ft_putendl_fd(char const *s, int fd);
void		ft_putendl(char const *s);

/*
**	Numbers
*/

void		ft_putlli_base_fd(t_lli nb, char const *base, int fd);
void		ft_putulli_base_fd(t_ulli nb, char const *base, int fd);

void		ft_putnbr_fd(t_lli nb, int fd);
void		ft_putnbr(t_lli nb);

void		ft_putbin_fd(t_ulli nb, int fd);
void		ft_putbin(t_ulli nb);

void		ft_putunbr_fd(t_ulli nb, int fd);
void		ft_putunbr(t_ulli nb);

void		ft_puthex_fd(t_ulli nb, int fd);
void		ft_puthex(t_ulli nb);

#endif
