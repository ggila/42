/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 18:41:01 by ggilaber          #+#    #+#             */
/*   Updated: 2015/01/21 22:14:36 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ft_cmp_int(void *s1, void *s2)
{
	t_key_sort	v1;
	t_key_sort	v2;
	int			b1;
	int			b2;

	v1 = *((t_key_sort*)s1);
	v2 = *((t_key_sort*)s2);
	b1 = v1.key.ent;
	b2 = v2.key.ent;
	if (b1 < b2)
		return (g_flag.reverse ? -1 : 1);
	else if (b1 > b2)
		return (g_flag.reverse ? 1 : -1);
	return (0);
}

int ft_cmp_time(void *s1, void *s2)
{
	time_t t1;
	time_t t2;

	t1 = ((t_key_sort*)s1)->key.time;
	t2 = ((t_key_sort*)s2)->key.time;
	if (t1 < t2)
		return (g_flag.reverse ? -1 : 1);
	else if (t1 > t2)
		return (g_flag.reverse ? 1 : -1);
	return (0);
}

int ft_cmp_file_dir(void *s1, void *s2)
{
	int n1;
	int n2;

	n1 = ft_is_dir(NULL, *(char**)s1, ft_strlen(*(char**)s1), 'm');
	n2 = ft_is_dir(NULL, *(char**)s2, ft_strlen(*(char**)s2), 'm');
	if (n1 && !n2)
		return (1);
	else if (!n1 && n2)
		return (-1);
	else
		return (0);
}

int ft_cmp_dot(void *s1, void *s2)
{
	int n1;
	int n2;

	n1 = **((char**)s1) == '.' ? 1 : 0;
	n2 = **((char**)s2) == '.' ? 1 : 0;
	if (n1 == n2)
		return (0);
	else if (n1 > n2)
		return (-1);
	else
		return (1);
}
