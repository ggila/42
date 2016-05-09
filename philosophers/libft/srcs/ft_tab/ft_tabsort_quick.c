/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsort_quick.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 16:44:29 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/21 18:13:02 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tab.h"

static void		s_strswap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}

static size_t	s_partition(char **tab, size_t first, size_t last,
					int (*cmpf)(char const *, char const *))
{
	size_t i;
	size_t j;

	i = first;
	j = first;
	while (j < last)
	{
		if (cmpf(tab[j], tab[last]) < 0)
		{
			s_strswap(tab + i, tab + j);
			i++;
		}
		j++;
	}
	s_strswap(tab + i, tab + last);
	return (i);
}

static void		s_quicksort(char **tab, size_t first, size_t last,
					int (*cmpf)(char const *, char const *))
{
	size_t		pivot;

	pivot = s_partition(tab, first, last, cmpf);
	if (first < pivot)
		s_quicksort(tab, first, pivot - 1, cmpf);
	if (pivot < last)
		s_quicksort(tab, pivot + 1, last, cmpf);
	return ;
}

void			ft_tabsort_quick(char **tab,
					int (*cmpf)(char const *, char const *))
{
	size_t	len;

	if (!tab || !cmpf || ((len = ft_tablen(tab)) < 2))
		return ;
	s_quicksort(tab, 0, ft_tablen(tab) - 1, cmpf);
	return ;
}
