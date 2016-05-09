/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 17:43:31 by ggilaber          #+#    #+#             */
/*   Updated: 2015/01/16 00:14:46 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** tab is a void pointer, it points to the first data to sort. This macro    *\
** returns a pointer to the nth data in tab.                                 **
*/

#define ARRAY_INDEX(tab, i) ((void*)((char*)tab + i * tosort->type_size))

/*
** STEP :                                                                    *\
**                                                                           **
** 1/ FT_MERGESORT_ARRAY                                                     **
** malloc and define a new t_merge struct with inputs. Malloc a void* aux to **
** help merging.                                                             **
**                                                                           **
** 2/ FT_MYSORT                                                              **
** to sort an array with mergesort :                                         **
** - sort the first half of the array,                                       **
** - sort the second half of the array,                                      **
** - merge both half together.                                               **
**                                                                           **
** 3/ MERGE                                                                  **
** tosort->tab is sorted between a and mid and beteween mid+1 and b.         **
** merge sorts all the data contained in both intervals. It first copies     **
** data from tosort->tab to aux and then compares the value of both          **
** intervals and copy the smallest in tosort->tab.                           **
**                                                                           **
**    AUX     |-2_|_0_|_2_|_5_|_7_|_8_|-1_|_1_|_3_|_4_|_6_|_9_|              **
**            a             |        mid                |     b              **
**                          i                           j                    **
**                                                                           **
**    TAB     |-2_|-1_|_0_|_2_|_3_|_4_|-1_|_1_|_3_|_4_|_6_|_9_|              **
**            a                         |                     b              **
**                                      k                                    **
**                                                                           **
** TOOLS :                                                                   **
** - ft_copy_tab copies datas between a and b from tosort->tab to aux.       **
** - ft_copy_index copies data from aux, index j, to tosort->tab, index i.   **
*/

static void		ft_copy_tab(t_merge *tosort, void *aux, int a, int b)
{
	void	*tab;
	void	*aux_start;

	aux_start = ARRAY_INDEX(aux, a);
	tab = ARRAY_INDEX(tosort->tab, a);
	ft_memmove(aux_start, tab, (b - a + 1) * tosort->type_size);
}

static void		ft_copy_index(t_merge *tosort, void *aux, int i, int j)
{
	void	*tab_i;
	void	*aux_j;

	tab_i = ARRAY_INDEX(tosort->tab, i);
	aux_j = ARRAY_INDEX(aux, j);
	ft_memmove(tab_i, aux_j, tosort->type_size);
}

static void		merge(t_merge *tosort, void *aux, int a, int b)
{
	int		i;
	int		j;
	int		k;
	int		mid;

	ft_copy_tab(tosort, aux, a, b);
	mid = (a + b) / 2;
	i = a;
	j = mid + 1;
	k = a;
	while (k <= b)
	{
		if (i > mid)
			ft_copy_index(tosort, aux, k, j++);
		else if (j > b)
			ft_copy_index(tosort, aux, k, i++);
		else if ((tosort->f_cmp)(ARRAY_INDEX(aux, i), ARRAY_INDEX(aux, j)) > 0)
			ft_copy_index(tosort, aux, k, j++);
		else
			ft_copy_index(tosort, aux, k, i++);
		k++;
	}
	return ;
}

static void		ft_sort(t_merge *tosort, void *aux, int a, int b)
{
	int mid;

	if (b <= a)
		return ;
	mid = (a + b) / 2;
	ft_sort(tosort, aux, a, mid);
	ft_sort(tosort, aux, mid + 1, b);
	merge(tosort, aux, a, b);
}

void			ft_my_sort(void *tab, int (*f_cmp)(void*, void*),
		int type_size, int last_index)
{
	void	*aux;
	t_merge	*tosort;

	if (!(tosort = (t_merge*)malloc(sizeof(t_merge))))
		return ;
	tosort->tab = tab;
	tosort->f_cmp = f_cmp;
	tosort->type_size = type_size;
	tosort->last_index = last_index;
	if (!(aux = ft_memalloc(type_size * (last_index + 1))))
		return ;
	ft_sort(tosort, aux, 0, last_index);
	free(tosort);
}
