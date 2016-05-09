/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 12:10:34 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/02 00:55:44 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include "libft.h"

# define OK 0
# define KO -1
# define STOP 2

# define LA 0
# define LB 1

# define A 2
# define B 3
# define S 6
# define R 6

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

# define NB_OP 11
# define NB_BRUTE 7

# define UNSORT 1

# define MASK 1
# define MASK_VERBOSE MASK<<1
# define MASK_TOGO MASK<<2
# define MASK_BRUTE MASK<<3
# define MASK_INSERTION MASK<<4
# define MASK_NB_OP MASK<<5

# define ABS(n) (((n) > 0) ? (n) : (-n))

typedef struct		s_sub
{
	struct s_dll	*first;
	struct s_dll	*last;
	int				size;
	char			way;
}					t_sub;

typedef struct		s_op_dll
{
	struct s_op_dll	*prev;
	struct s_op_dll	*next;
	char			op;
	char			pos;
	char			op_flag;
}					t_op_dll;

typedef struct		s_dll
{
	int				n;
	int				togo;
	struct s_dll	*prev;
	struct s_dll	*next;
	t_sub			*sub;
	char			way;
}					t_dll;

typedef struct		s_size
{
	int				l_a;
	int				l_b;
	int				total;
	int				mid;
	int				l_op;
	int				sub;
}					t_size;

typedef void		(*t_ft_op)(char c);

# define ARRAY_INDEX(tab, i) ((void*)((char*)tab + i * tosort.type_size))

typedef struct		s_merge
{
	void			*tab;
	int				(*f_cmp)(const void*, const void*);
	int				type_size;
	int				last_index;
}					t_merge;

t_dll				*g_l_a;
t_dll				*g_l_b;
t_op_dll			*g_l_op;
char				g_op[11][4];
void				(*g_ft_op[11])(void);
t_size				g_size;
int					g_flag;

int					ft_decrease(void);
char				ft_l_sorted(t_dll *l_b, char c);
char				ft_sort(t_dll *l_b);
int					ft_quit(char c);
void				ft_bruteforce(void);
void				ft_brute_undo(t_op_dll *l_init,
					void (*ft_op_inv[11])(void));
void				ft_sort_three(void);
void				ft_check_small_list(t_sub sub[]);
char				ft_l_sorted(t_dll *l, char c);
char				ft_sort(t_dll *l_a);
t_dll				*ft_dll_set(int ac, char **av);
void				ft_init_all(int ac, char **av, t_sub **sub);
void				ft_fill_lb(void);
void				ft_fill_la(void);
void				ft_finish(void);
int					ft_check_way(int togo);
void				*ft_memalloc(size_t size);
void				ft_print_flag(void);
void				ft_insertion(void);
void				ft_reverse(t_dll *end, int size);
void				ft_ordered_list(char c);
int					f_cmp(const void *x, const void *y);
void				ft_get_opt(int *ac, char ***av);
void				ft_set_merge(t_sub *sub);
void				ft_reorder_way(t_dll *l);
void				ft_merge(void);
void				ft_op_add(char op);
void				ft_push_gen(t_dll **l1, t_dll **l2);
t_dll				*ft_dll_add(t_dll *dll, char *av, t_dll **last, int *tab);
void				ft_swap(char l);
void				ft_push(char l);
void				ft_rotate_left(char l);
void				ft_rotate_right(char l);
void				ft_putsub(t_sub *sub);
void				ft_putdll(t_dll *dll);
void				ft_putddll(void);
void				ft_putop(char op);
void				ft_print_opdll(t_op_dll *l_op);
void				ft_swap_a(void);
void				ft_swap_b(void);
void				ft_swap_s(void);
void				ft_push_a(void);
void				ft_push_b(void);
void				ft_rotate_left_a(void);
void				ft_rotate_left_b(void);
void				ft_rotate_left_r(void);
void				ft_rotate_right_a(void);
void				ft_rotate_right_b(void);
void				ft_rotate_right_r(void);
void				ft_init_op_inv(void (*ft_op_inv[11])(void));
void				ft_op_init(void);
void				ft_mergesort_array(void *tab,
					int (*f_cmp)(const void*, const void*), int type_size,
					int last_index);

#endif
