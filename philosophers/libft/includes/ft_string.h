/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:31:30 by jsaglio           #+#    #+#             */
/*   Updated: 2015/10/13 00:49:21 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>

# define T_STRING_DFLT_CAP		16
# define FT_STRING_INIT(ptr)	ptr = ft_string_new(0)
# define FT_STRING_DEL(ptr)		ft_string_del(&ptr)

typedef struct	s_string
{
	char		*str;
	size_t		len;
	size_t		capacity;
}				t_string;

t_string		*ft_string_new(size_t size);
void			ft_string_del(t_string **str_ptr);

t_string		*ft_string_convert(const char *src);
t_string		*ft_string_sub(char const *src, size_t n);
int				ft_string_clear(t_string *str);
int				ft_string_resize(t_string *str, size_t size);

int				ft_string_add(t_string *dst, char c);
int				ft_string_insert(t_string *dst, size_t pos, char *str);
int				ft_string_remove(t_string *dst, size_t pos, size_t n);
int				ft_string_cpy(t_string *dst, const char *src);
int				ft_string_ncpy(t_string *dst, const char *src, size_t n);
int				ft_string_cat(t_string *dst, const char *src);
int				ft_string_ncat(t_string *dst, const char *src, size_t n);

#endif
