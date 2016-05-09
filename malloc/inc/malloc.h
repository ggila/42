/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 16:53:13 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/02 16:48:50 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>

# define TINY 1007
# define SMALL 8192

# define SET_RED ft_putstr("\033[1;31m")
# define SET_GREEN ft_putstr("\033[1;32m")
# define SET_YELLOW ft_putstr("\033[1;33m")
# define SET_WHITE ft_putstr("\033[1;37m")

# define ADD(ptr, of) (void*)((char*)ptr + of)
# define NEXT(ptr) (void*)((char*)ptr + *(size_t*)ptr)
# define SIZE(ptr) *(size_t*)ptr
# define LAST_SIZE(ptr) *(size_t*)ADD(ptr, *(size_t*)ptr - sizeof(size_t))

typedef struct	s_free
{
	size_t			size;
	struct s_free	*p;
	struct s_free	*n;
}				t_free;

typedef struct	s_reg
{
	struct s_reg	*p;
	struct s_reg	*n;
	t_free			*free;
	size_t			size;
}				t_reg;

typedef struct	s_glob
{
	t_reg		*tiny;
	t_reg		*small;
	t_reg		*large;
}				t_glob;

// src/
void			*malloc(size_t size);
void			free(void *ptr);
void			*realloc(void *ptr, size_t size);

//show_alloc_mem.c
void			show_alloc_mem(void);
void			show_region(t_reg *reg);
void			show_region_deb(t_reg *reg);

// src/region
void			*fromnewregion(t_reg **reg, size_t size);
void			*fromregions(t_reg *region, size_t size);
void			setnewregion(t_reg *new_reg, t_reg **reg,
						size_t block_size, size_t reg_size);

// src/bloc
void			*setblock(void *ptr, size_t block_size);
t_reg			*blockregion(void *ptr, t_reg ***regs);
void			checkaroundblock(t_reg *reg, void *ptr, void *around[2]);
void			setfreeblock(t_free *block, t_reg *reg, void *around[2]);
void			enlargeblock(void *ptr, size_t size, t_reg *reg);

// src/lib
void			ft_putstr(char const *str);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_putptr(void *ptr);
void			ft_printptr(void *p1, void *p);
void			ft_printnbr(void *p1, int n);
void			ft_printarea(void *p1, void *p2, int n);
void			ft_putnbr(int n);
void			ft_putchar(char c);
char			ft_env(char *str);

#endif
