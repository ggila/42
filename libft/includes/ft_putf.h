/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 16:30:29 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/07 11:06:29 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTF_H
# define FT_PUTF_H

# include <stdarg.h>

void			ft_vputf_fd(int fd, const char *str, va_list ap);
void			ft_putf_fd(int fd, const char *str, ...);

void			ft_vputf(const char *str, va_list ap);
void			ft_putf(const char *str, ...);

#endif
