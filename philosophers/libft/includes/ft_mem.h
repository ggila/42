/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:31:30 by jsaglio           #+#    #+#             */
/*   Updated: 2015/12/03 15:06:49 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

# include <stdlib.h>

# define FT_MALLOC(type, count)		((type *)malloc(sizeof(type) * (count)))
# define FT_ZMALLOC(type, count)	ft_memalloc(sizeof(type) * (count))
# define FT_ZERO(varname)			ft_bzero(&varname, sizeof(varname))

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memnew(size_t size_of, size_t count);
void				ft_memdel(void **ap);

#endif
