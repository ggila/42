/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:31:30 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/06 21:39:02 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MISC_H
# define FT_MISC_H

# include <stddef.h>
# include "ft_typedef.h"

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isdigit_only(char *str);
int					ft_isspace(int c);
size_t				ft_ilen(t_lli n);
t_lli				ft_iabs(t_lli n);
t_lli				ft_imin(t_lli a, t_lli b);
t_lli				ft_imax(t_lli a, t_lli b);

#endif
